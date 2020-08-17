#pragma once

#include <SFML/System/Vector2.hpp>
#include <functional>

class I_SFMLClickable
{
public:
   typedef std::function<void()> Action;

   // Retourne vrai si la souris est sur le bouton, faux sinon
   virtual bool isSelected(const sf::Vector2f mouse_pos) const = 0;
};

