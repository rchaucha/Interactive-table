#pragma once

#include <SFML/Audio.hpp>
#include "Command.hpp"
#include "tools/FilesManager.hpp"

class PlaySoundCommand : public Command
{
public:
   PlaySoundCommand(const std::string activity_file_name, const std::string filepath) :
      _filepath(filepath),
      _activity_file_name(activity_file_name)
   {}

   virtual void execute() const override 
   { 
      FilesManager::playSound(_activity_file_name, _filepath);
   }

private:
   const std::string _filepath, _activity_file_name;
};
