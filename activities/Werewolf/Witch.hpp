#pragma once

#include "activities/Werewolf/Character.hpp"

class Witch : public Character
{
   virtual const std::string getName() const override { return "Sorcière"; };
};

