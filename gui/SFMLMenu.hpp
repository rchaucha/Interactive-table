#pragma once

#include <vector>
#include <map>
#include "SFMLButton.hpp"
#include "SFMLButtonFolder.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class SFMLMenu : public std::vector<SFMLButtonFolder>
{
public:
   typedef std::vector<SFMLButtonFolder>::const_iterator iterator;

   bool isLastPage() { return (this->size() / BUT_PER_PAGE == _current_page_nbr); } const
   
   void nextPage() { _current_page_nbr++; }

   void draw(sf::RenderWindow& window) const;

   bool addInFolder(long ID, SFMLButton &b);

private:
   iterator getFirstOfPage(unsigned int page_nbr) const;

   /* Nombre de boutons sur une ligne / colonne */
   static const int BUT_PER_ROW = 3;

   static const int BUT_PER_PAGE = BUT_PER_ROW * BUT_PER_ROW;

   /* Page courante, la première est la page 0 */
   unsigned int _current_page_nbr;

   map<long, int> _id2index;
};
