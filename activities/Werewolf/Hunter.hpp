#pragma once

#include "activities/Werewolf/Character.hpp"

class Hunter : public Character
{
   virtual const std::string getName() const override { return "Chasseur"; };
};

