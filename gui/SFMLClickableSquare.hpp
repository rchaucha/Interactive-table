#pragma once

#include "I_SFMLClickable.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class SFMLClickableSquare : public I_SFMLClickable, public sf::RectangleShape
{
public:
   SFMLClickableSquare(sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture);

   bool isSelected(const sf::Vector2f mouse_pos) const override;
};
