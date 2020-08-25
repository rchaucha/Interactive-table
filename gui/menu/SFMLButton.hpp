#pragma once

#include "SFMLClickableSquare.hpp"
#include <SFML/Graphics/Texture.hpp>

class SFMLButton : public SFMLClickableSquare
{
public:
   SFMLButton(const std::string name, std::shared_ptr<Activity> activity, sf::Texture texture, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(0,0)) :
      SFMLClickableSquare(activity, texture, pos, size),
      _name(name)
   {}

   std::string getName() { return _name; }

private:
   const std::string _name;
};
