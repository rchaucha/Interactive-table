#include "SFMLMenuModel.hpp"

using namespace std;
using namespace sf;


class SFMLMenuModel::SFMLFolder : public SFMLClickableSquare
{
public:
   SFMLFolder(std::vector<SFMLButton> buttons, sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture) :
      SFMLClickableSquare(pos, size, texture)
   {}

   void constexpr add(SFMLButton& b) { _buttons.push_back(b); }

private:
   std::vector<SFMLButton> _buttons;
};


class SFMLMenuModel::SFMLAppLauncher : SFMLMenuModel::SFMLFolder
{

};


bool SFMLMenuModel::addInFolder(unsigned int ID, SFMLButton &b)
{
   auto ind_it = _id2index.find(ID);
   if (ind_it == _id2index.end())
      return false;

   _buttons.at[*ind_it].add(b);
   return true;
}

auto SFMLMenuModel::getFirstOfPage(unsigned short page_nbr) const
{
   auto it = _buttons.begin();
   advance(it, SFMLMenuView::BUTTONS_PER_PAGE * _current_page_nbr);

   return it;
}
