#include "SFMLButton.h"

using namespace sf;

SFMLButton::SFMLButton(Vector2f pos, Vector2f size, Texture& texture) :
   RectangleShape(size)
{
   this->setPosition(pos);
   this->setTexture(&texture);
   this->setOutlineColor(Color::Black);
   this->setOutlineThickness(1);
}

bool SFMLButton::isClicked(const sf::Vector2f mouse_pos) const
{
   return this->getGlobalBounds().contains(mouse_pos);
}
