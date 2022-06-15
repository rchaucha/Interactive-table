#pragma once

#include <SFML/System/Vector2.hpp>
#include "commands\Command.hpp"

class SFMLButton
{
public:
   SFMLButton(const Command* command);
      
   virtual ~SFMLButton() { delete _command; }

   // Retourne vrai si la souris est sur le bouton, faux sinon
   virtual bool isSelected(const sf::Vector2f mouse_pos) const = 0;
   
   void execute() const { _command->execute(); }

   const unsigned int getID() const noexcept { return _ID; }

   bool operator==(const SFMLButton& other);

private:
   const Command* _command;

   const unsigned int _ID;
   static unsigned int _id_generator;
};
