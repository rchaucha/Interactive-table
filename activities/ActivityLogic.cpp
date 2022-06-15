#include "ActivityLogic.hpp"

unsigned int ActivityLogic::_id_generator = 0;

ActivityLogic::ActivityLogic():
   _ID(_id_generator),
   _rgb_cam(RGBCameraInput::getInstance())
{
   _id_generator++;
}


bool ActivityLogic::operator==(const ActivityLogic& other)
{
   return _ID == other._ID;
}