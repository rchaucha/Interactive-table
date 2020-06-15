#pragma once

#include "Activity.hpp"

class MainActivity : public Activity
{
protected:
   MainActivity(const sf::Vector2u window_size, const sf::Vector2u frame_size) : 
      Activity(window_size, frame_size){}
};
