#pragma once

class Command
{
public:
   virtual ~Command() {}

   virtual void execute() const = 0;
};

