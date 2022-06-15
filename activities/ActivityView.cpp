#include "ActivityView.hpp"


sf::Vector2f ActivityView::frame2Window(const sf::Vector2f frame_coordinates) const
{
   float x = frame_coordinates.x * (_window_size.x / float(_frame_size.x));
   float y = frame_coordinates.y * (_window_size.y / float(_frame_size.y));
   return sf::Vector2f(x, y);
}