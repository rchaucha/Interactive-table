#pragma once

#include <vector>
#include "gui/SFMLButton.hpp"

class SFMLButtonFolder : public SFMLButton
{
public:
   SFMLButtonFolder(std::vector<SFMLButton> buttons, sf::Vector2f pos, sf::Vector2f size, sf::Texture& texture);

   static void _action();
private:
   std::vector<SFMLButton> _buttons;
};

