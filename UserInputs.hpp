#pragma once

#include <string>

class UserInputs
{
public:
   UserInputs(std::string window) :
      _window(window)
   {}

private:
   void CallBackFunc(int event, int x, int y, int flags, void* userdata);
   std::string _window;
};
