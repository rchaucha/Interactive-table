#include "Activity.hpp"


Activity::Activity(const sf::Vector2u window_size, const sf::Vector2u frame_size) :
   _window_size(window_size),
   _frame_size(frame_size)
{}

sf::Vector2f Activity::frame2Window(const sf::Vector2f frame_coordinates) const
{
   float x = frame_coordinates.x * (_window_size.x / float(_frame_size.x));
   float y = frame_coordinates.y * (_window_size.y / float(_frame_size.y));
   return sf::Vector2f(x, y);
}
