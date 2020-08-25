#pragma once

#include "Activity.hpp"

class MainActivity : public Activity
{
public:
  // virtual std::shared_ptr<MainActivity> makeUniqueMain() const = 0;

protected:
   MainActivity(const sf::Vector2u window_size, const sf::Vector2u frame_size) : 
      Activity(window_size, frame_size){}

};
