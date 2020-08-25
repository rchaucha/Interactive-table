#include "activities/GlassTrackingActivity.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include "tools/FilesManager.hpp"

using namespace cv;
using namespace std;
using namespace sf;


GlassTrackingActivity::GlassTrackingActivity(const sf::Vector2u window_size, const Vector2u frame_size) :
   SecondaryActivity(window_size, frame_size)
{}

void GlassTrackingActivity::run(cv::Mat frame)
{
   _glasses_tracking.init(frame);
   _last_frame = frame;
}

void GlassTrackingActivity::update(cv::Mat frame)
{
   _glasses_tracking.update(frame);
   _last_frame = frame;
}

bool GlassTrackingActivity::catchEvent(sf::Event event)
{
   if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
   {
      resetTrackers();
      return true;
   }
   return false;
}

vector<shared_ptr<Drawable>> GlassTrackingActivity::getDrawables() const
{
   vector<shared_ptr<sf::Drawable>> drawables;
   vector<cv::Rect2d> roi = _glasses_tracking.getROI();

   // Rectangles correspondant aux verres
   for (const auto& rect : roi)
   {
      sf::RectangleShape* rectangle = new RectangleShape(frame2Window(Vector2f(rect.width, rect.height)));
      rectangle->setPosition(frame2Window(Vector2f(rect.x, rect.y)));
      rectangle->setOutlineThickness(3.f);
      rectangle->setOutlineColor(sf::Color::Green);

      drawables.push_back(shared_ptr<sf::RectangleShape>(rectangle));
   }

   return drawables;
}

void GlassTrackingActivity::buttonClicked(string button_id)
{
   if (button_id == "reset")
      resetTrackers();
}

vector<shared_ptr<SFMLButton>> GlassTrackingActivity::getButtons()
{
   vector<shared_ptr<SFMLButton>> buttons;
   Texture texture = FilesManager::loadImgTexture(getFolderName() + "/reset.png");

   SFMLButton b_reset("reset", shared_from_this(), texture);
   buttons.push_back(make_shared<SFMLButton>(b_reset));

   return buttons;
}

string GlassTrackingActivity::getFolderName() const
{
   return "glass_tracking";
}

void GlassTrackingActivity::resetTrackers()
{
   cout << "Reinitialisation des trackers" << endl;
   _glasses_tracking.init(_last_frame);
}