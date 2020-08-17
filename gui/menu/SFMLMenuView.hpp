#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <gui/menu/SFMLClickableSquare.hpp>

class SFMLMenuView
{
public:
   /* Nombre de boutons sur une ligne / colonne */
   static const unsigned int BUTTONS_PER_ROW = 3;
   static constexpr unsigned int BUTTONS_PER_PAGE = BUTTONS_PER_ROW * BUTTONS_PER_ROW;

   void draw(sf::RenderWindow& window) const;
   void update(const std::vector<const SFMLClickableSquare> icons, bool is_first_page, bool is_last_page);

private:
   // Pointeur vers le tableau d'icones
   std::vector<const SFMLClickableSquare> _icons_array;
   bool _is_first_page;
   bool _is_last_page;
};
