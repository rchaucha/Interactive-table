#include "activities/GlassTrackingActivity.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

using namespace cv;
using namespace std;
using namespace sf;

GlassTrackingActivity::GlassTrackingActivity(const sf::Vector2u window_size, Mat frame) :
   SecondaryActivity(window_size)
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

vector<unique_ptr<Drawable>> GlassTrackingActivity::getDrawables() const
{
   vector<unique_ptr<sf::Drawable>> drawables;
   vector<cv::Rect2d> roi = _glasses_tracking.getROI();

   for (cv::Rect2d rect : roi)
   {
      sf::RectangleShape* rectangle = new RectangleShape(Vector2f(float(rect.width), float(rect.height)));
      rectangle->setOutlineThickness(3.f);
      rectangle->setOutlineColor(sf::Color::Black);
      sf::Vector2f pos = getWindowPos(sf::Vector2f(rect.x, rect.y), sf::Vector2u(_last_frame.cols, _last_frame.rows));
      rectangle->setPosition(pos);

      drawables.push_back(unique_ptr<sf::RectangleShape>(rectangle));
   }

   return drawables;
}
