#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class SFMLButton : public sf::RectangleShape
{
public:
   SFMLButton(sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture);

   bool isClicked(const sf::Vector2f mouse_pos) const;
};

