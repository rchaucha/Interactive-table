#pragma once

#include "Activity.hpp"

class SecondaryActivity : public Activity
{
public:
   //virtual std::shared_ptr<SecondaryActivity> makeUniqueSecondary() const = 0;

protected:
   SecondaryActivity(const sf::Vector2u window_size, const sf::Vector2u frame_size) :
      Activity(window_size, frame_size) {}

};