#include "activities/GlassTrackingActivity.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

using namespace cv;
using namespace std;
using namespace sf;

GlassTrackingActivity::GlassTrackingActivity(const sf::Vector2u window_size, Mat frame) :
   SecondaryActivity(window_size, Vector2u(frame.cols, frame.rows))
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
      cout << "Reinitialisation des trackers" << endl;
      _glasses_tracking.init(_last_frame);

      return true;
   }
   return false;
}

vector<unique_ptr<Drawable>> GlassTrackingActivity::getDrawables() const
{
   vector<unique_ptr<sf::Drawable>> drawables;
   vector<cv::Rect2d> roi = _glasses_tracking.getROI();

   // Rectangles correspondants aux verres
   for (cv::Rect2d rect : roi)
   {
      sf::RectangleShape* rectangle = new RectangleShape(frame2Window(Vector2f(rect.width, rect.height)));
      rectangle->setPosition(frame2Window(Vector2f(rect.x, rect.y)));
      rectangle->setOutlineThickness(3.f);
      rectangle->setOutlineColor(sf::Color::Black);

      drawables.push_back(unique_ptr<sf::RectangleShape>(rectangle));
   }
   
   return drawables;
}
