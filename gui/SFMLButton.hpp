#pragma once

#include "SFMLClickableSquare.hpp"
#include <SFML/Graphics/Texture.hpp>

class SFMLButton : SFMLClickableSquare
{
public:
   SFMLButton(const Action action, sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture);
   
   // Exécute l'action associée au bouton
   const Action execute;
};
