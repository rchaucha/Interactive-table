#pragma once

#include "Activity.hpp"

class SecondaryActivity : public Activity
{
protected:
   SecondaryActivity(const sf::Vector2u window_size) : Activity(window_size) {}
};