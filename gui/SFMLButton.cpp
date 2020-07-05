#include "SFMLButton.hpp"

using namespace sf;

SFMLButton::SFMLButton(Action action, Vector2f pos, Vector2f size, Texture& texture) :
   RectangleShape(size),
   execute(action)
{
   setPosition(pos);
   setTexture(&texture);
}

bool SFMLButton::isSelected(const sf::Vector2f mouse_pos) const
{
   return getGlobalBounds().contains(mouse_pos);
}
