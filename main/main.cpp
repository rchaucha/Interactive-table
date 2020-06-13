#include <iostream>

#include "gui/Window.hpp"
#include "activities/MenuActivity.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
   VideoCapture cap;

   if (!cap.open(0))
      cerr << "La webcam est introuvable" << endl;
   else
   {
      MenuActivity menu;
      Window window(menu, cap);

      window.launch();
   }

   return 0;
}
