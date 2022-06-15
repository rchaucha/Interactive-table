#include "activities/GlassTracking/GlassTrackingActivity.hpp"

#include <time.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include "tools/FilesManager.hpp"


GlassTrackingActivity::GlassTrackingActivity(GlassTrackingActivityView* view):
   _view(view)
{
   _view->setActivityLogic(this);
}

GlassTrackingActivity::~GlassTrackingActivity()
{
   delete _view;
}

void GlassTrackingActivity::run()
{
   resetTrackers();

   srand((unsigned)time(NULL));
      
   _view->loadTextures();
}

void GlassTrackingActivity::update()
{
   _glasses_tracking.update(_rgb_cam->getFrame());

   _view->update(_glasses_tracking.getROI());
}

void GlassTrackingActivity::resetTrackers()
{
   std::cout << "Initialisation des trackers" << std::endl;
   _glasses_tracking.init(_rgb_cam->getFrame());
   _view->setGlassesTexture();
}
