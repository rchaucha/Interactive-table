#include "SFMLButtonFolder.hpp"

SFMLButtonFolder::SFMLButtonFolder(std::vector<SFMLButton> buttons, sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture):
   SFMLButton(_action, pos, size, texture),
   _buttons(buttons)
{}

void SFMLButtonFolder::action()
{
   if (_buttons.size() == 1)
      _buttons[0].push();
}
