#pragma once

#include "activities/Werewolf/Character.hpp"

class Villager : public Character
{
   virtual const std::string getName() const override { return "Villageois"; };
};
