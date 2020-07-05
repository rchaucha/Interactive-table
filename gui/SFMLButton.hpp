#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

class SFMLButton : public sf::RectangleShape
{
public:
   typedef std::function<void()> Action;

   SFMLButton(const Action action, sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture);

   /* Retourne vrai si la souris est sur le bouton, faux sinon */
   bool isSelected(const sf::Vector2f mouse_pos) const;

   /* Exécute l'action associée au bouton */
   const Action execute;
};
