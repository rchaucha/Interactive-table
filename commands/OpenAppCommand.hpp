#pragma once

#include "Command.hpp"
#include <activities\ActivitiesManager.hpp>

class OpenAppCommand : public Command
{
public:
   OpenAppCommand(const std::size_t button_index, std::shared_ptr<ActivityLogic> activity, SFMLMenu* menu) :
      _activity(activity),
      _menu(menu),
      _button_index(button_index)
   {}

   virtual void execute() const override 
   { 
      ActivitiesManager::launchActivity(_activity); 
      _menu->openActivity(_activity, _button_index);
   }

private:
   const std::size_t _button_index;
   std::shared_ptr<ActivityLogic> _activity;
   SFMLMenu* _menu;
};
