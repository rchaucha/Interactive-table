#include "SFMLClickableSquare.hpp"

SFMLClickableSquare::SFMLClickableSquare(sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture):
   sf::RectangleShape(size)
{
   setPosition(pos);
   setTexture(&texture);
}

bool SFMLClickableSquare::isSelected(const sf::Vector2f mouse_pos) const
{
   return getGlobalBounds().contains(mouse_pos);
}
