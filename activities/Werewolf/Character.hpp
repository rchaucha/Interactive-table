#pragma once
#include <string>
#include <optional>

class Character
{
public:
   Character() 
      : _loved_one(std::nullopt) 
   {}

   virtual const std::string getName() const = 0;

   virtual std::optional<unsigned char> getLovedOne() const final { return _loved_one; }
   virtual void setLovedOne(const unsigned char ID) final { _loved_one = ID; }

private:
   std::optional<unsigned char> _loved_one;
};

