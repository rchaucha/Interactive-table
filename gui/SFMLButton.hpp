#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

class SFMLButton : public sf::RectangleShape
{
public:
   typedef std::function<void()> Action;

   SFMLButton(const Action action, sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture);

   bool press(const sf::Vector2f mouse_pos) const;

protected:
   const Action _action;
};
