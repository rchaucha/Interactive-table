#pragma once

#include <list>
#include "SFMLButton.hpp"

class SFMLButtonsManager : public std::list<SFMLButton>
{
public:
   typedef std::list<SFMLButton>::const_iterator iterator;

   bool isLastPage() { return (this->size() / NBR_BUTTONS_PER_PAGE == _current_page_nbr); }

   

private:
   static const int NBR_BUTTONS_PER_PAGE = 9;

   /* Page courante, la première est la page 0 */
   unsigned int _current_page_nbr;
};
