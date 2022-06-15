#pragma once

#include "Command.hpp"
#include "gui/menu/SFMLMenu.hpp"

class CloseAppCommand : public Command
{
public:
   CloseAppCommand(const std::size_t button_index, std::shared_ptr<ActivityLogic> activity_to_close, SFMLMenu* menu) :
      _activity_to_close(activity_to_close),
      _menu(menu),
      _button_index(button_index)
   {}

   virtual void execute() const override
   {
      ActivitiesManager::stopActivity(_activity_to_close->getId());
      _menu->closeActivity(_activity_to_close, _button_index);
   }

private:
   const std::size_t _button_index;
   std::shared_ptr<ActivityLogic> _activity_to_close;
   SFMLMenu* _menu;
};
