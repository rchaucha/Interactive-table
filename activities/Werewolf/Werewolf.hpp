#pragma once

#include "activities/Werewolf/Character.hpp"

class Werewolf : public Character
{
   virtual const std::string getName() const override { return "Loup-garou"; };
};

