#pragma once

#include "Activity.hpp"

class MainActivity : public Activity
{
protected:
   MainActivity(const sf::Vector2u window_size) : Activity(window_size){}
};
