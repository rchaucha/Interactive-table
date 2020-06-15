#include "SFMLButton.hpp"

using namespace sf;

SFMLButton::SFMLButton(Action action, Vector2f pos, Vector2f size, Texture& texture) :
   RectangleShape(size),
   _action(action)
{
   setPosition(pos);
   setTexture(&texture);
}

bool SFMLButton::press(const sf::Vector2f mouse_pos) const
{
   if (getGlobalBounds().contains(mouse_pos))
   {
      _action();
      return true;
   }

   return false;
}
