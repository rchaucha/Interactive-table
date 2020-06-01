#include "UserInputs.hpp"

#include <opencv2\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void UserInputs::CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
   if (event == EVENT_RBUTTONDOWN)
   {
      cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
   }
}
