#include "SFMLButton.hpp"

unsigned int SFMLButton::_id_generator = 0;

SFMLButton::SFMLButton(const Command* command):
   _ID(_id_generator),
   _command(command)
{
   _id_generator++;
}

bool SFMLButton::operator==(const SFMLButton& other)
{
   return other._ID == _ID;
}