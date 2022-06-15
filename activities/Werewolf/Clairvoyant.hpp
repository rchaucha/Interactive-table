#pragma once

#include "activities/Werewolf/Character.hpp"

class Clairvoyant : public Character
{
   virtual const std::string getName() const override { return "Voyante"; };
};

