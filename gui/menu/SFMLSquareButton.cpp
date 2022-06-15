#include "SFMLSquareButton.hpp"

#include "activities\ActivityLogic.hpp"
#include "activities\NoneActivity.hpp"

using namespace sf;
using namespace std;


SFMLSquareButton::SFMLSquareButton(const Command* command, Texture texture, Vector2f pos, Vector2f size):
   SFMLButton(command),
   RectangleShape(size),
   _texture(texture)
{
   setPosition(pos);
   setTexture(&_texture);
}

bool SFMLSquareButton::isSelected(const Vector2f mouse_pos) const
{
   return getGlobalBounds().contains(mouse_pos);
}