#pragma once

#include <vector>
#include <map>
#include "SFMLButton.hpp"
#include "SFMLMenuView.hpp"

class SFMLMenuModel
{
public:
   bool isLastPage() { return (_buttons.size() / SFMLMenuView::BUTTONS_PER_PAGE == _current_page_nbr); } const
   
   void constexpr nextPage() noexcept { _current_page_nbr++; }

   bool addInFolder(unsigned int ID, SFMLButton &b);

private:
   class SFMLFolder;
   class SFMLAppLauncher;

   auto getFirstOfPage(unsigned short page_nbr) const;

   /* Page courante, la première est la page 0 */
   unsigned short _current_page_nbr;

   std::map<unsigned int, unsigned int> _id2index;

   std::vector<SFMLClickableSquare> _buttons;
};
