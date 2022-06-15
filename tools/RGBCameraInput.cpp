#include "RGBCameraInput.hpp"

RGBCameraInput* RGBCameraInput::_instance = nullptr;

RGBCameraInput* RGBCameraInput::getInstance()
{
   if (_instance == nullptr)
      _instance = new RGBCameraInput();

   return _instance;
}
