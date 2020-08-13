#include "SFMLButton.hpp"

using namespace sf;

SFMLButton::SFMLButton(Action action, Vector2f pos, Vector2f size, Texture& texture) :
   SFMLClickableSquare(pos, size, texture),
   execute(action)
{}
