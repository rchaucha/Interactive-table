#include "SFMLMenu.hpp"


using namespace std;
using namespace sf;

void SFMLMenu::draw(RenderWindow& window) const
{
   int num_button = 1;
   auto w_size = window.getSize();

   int but_size = BUT_PER_ROW * w_size.y / 15;    // taille des boutons
   int space_size = (BUT_PER_ROW - 1) * but_size / 4;   // taille des espaces entre les boutons

   int y = (w_size.y - but_size - space_size) / 2;
   int x = (w_size.x - but_size - space_size) / 2,
   const int x0 = x;

   sf::RectangleShape* rect;
   for (iterator it = getFirstOfPage(_current_page_nbr); 
      num_button <= BUT_PER_PAGE && it != this->end(); ++it)
   {
      rect = new RectangleShape(*it);
      rect->setPosition(x, y);
      rect->setOutlineThickness(3.f);
      rect->setOutlineColor(sf::Color::Black);
      rect->setSize(Vector2f(but_size, but_size));

      window.draw(*rect);
      
      if (num_button % BUT_PER_ROW == 0)  // on revient à la ligne
      {
         x = x0;
         y += but_size + space_size;
      }
      else
         x += but_size + space_size;
      
      num_button++;
   }
}

bool SFMLMenu::addInFolder(long ID, SFMLButton &b)
{
   auto ind_it = _id2index.find(ID);
   if (ind_it == _id2index.end())
      return false;

   this->at[*ind_it].add(b);
   return true;
}

SFMLMenu::iterator SFMLMenu::getFirstOfPage(unsigned int page_nbr) const
{
   iterator it = this->begin();
   advance(it, BUT_PER_PAGE * _current_page_nbr);

   return it;
}
