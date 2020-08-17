#include "SFMLMenuView.hpp"

using namespace sf;

SFMLMenuView::SFMLMenuView(const unsigned int BUTTONS_PER_ROW, const unsigned int BUTTONS_PER_PAGE):
   BUTTONS_PER_ROW(BUTTONS_PER_ROW),
   BUTTONS_PER_PAGE(BUTTONS_PER_PAGE)
{}

void SFMLMenuView::draw(sf::RenderWindow& window) const
{
   int num_button = 1;
   auto w_size = window.getSize();

   int but_size = BUTTONS_PER_ROW * w_size.y / 15;    // taille des boutons
   int space_size = (BUTTONS_PER_ROW - 1) * but_size / 4;   // taille des espaces entre les boutons

   int y = (w_size.y - but_size - space_size) / 2;
   int x = (w_size.x - but_size - space_size) / 2;
   const int x0 = x;

   sf::RectangleShape* rect;
   for (auto icon : _icons_array)
   {
      rect = new RectangleShape(*it);
      rect->setPosition(x, y);
      rect->setOutlineThickness(3.f);
      rect->setOutlineColor(sf::Color::Black);
      rect->setSize(Vector2f(but_size, but_size));

      window.draw(*rect);

      if (num_button % BUTTONS_PER_ROW == 0)  // on revient à la ligne
      {
         x = x0;
         y += but_size + space_size;
      }
      else
         x += but_size + space_size;

      num_button++;
   }
}

void SFMLMenuView::update(const std::vector<const SFMLClickableSquare> icons, bool is_first_page, bool is_last_page)
{
   _icons_array = icons;
   _is_first_page = is_first_page;
   _is_last_page = is_last_page;
}
