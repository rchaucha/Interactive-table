#include "activities/GlassTrackingActivity.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

using namespace cv;
using namespace std;
using namespace sf;

GlassTrackingActivity::GlassTrackingActivity(Mat frame)
{
   _glasses_tracking.init(frame);
   _last_frame = frame;
}

void GlassTrackingActivity::run(cv::Mat frame)
{
   _glasses_tracking.update(frame);
   _last_frame = frame;
}

bool GlassTrackingActivity::catchEvent(sf::Event event)
{
   if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
   {
      cout << "Reinitialisation des trackers" << endl;
      _glasses_tracking.init(_last_frame);

      return true;
   }
   return false;
}

vector<unique_ptr<Drawable>> GlassTrackingActivity::getDrawables()
{
   vector<unique_ptr<sf::Drawable>> drawables;
   vector<cv::Rect2d> roi = _glasses_tracking.getROI();

   for (cv::Rect2d rect : roi)
   {
      sf::RectangleShape* rectangle = new RectangleShape(Vector2f(rect.width, rect.height));
      rectangle->setPosition(rect.x, rect.y);
      drawables.push_back(unique_ptr<sf::RectangleShape>(rectangle));
   }

   return drawables;
}
