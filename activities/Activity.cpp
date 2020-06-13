#include "Activity.hpp"


sf::Vector2f Activity::getWindowPos(const sf::Vector2f pos, const sf::Vector2u frame_size) const
{
   float x = pos.x * (_window_size.x / frame_size.x);
   float y = pos.y * (_window_size.y / frame_size.y);
   return sf::Vector2f(x, y);
}
