#include "FilesManager.hpp"

#include <iostream>

using namespace sf;
using namespace std;

const string FilesManager::FILES_PATH = "../../../files/";

Texture FilesManager::loadImgTexture(const string path)
{
   Texture texture;

   if (!texture.loadFromFile(FILES_PATH + "img/" + path))
   {
      cerr << "Impossible de charger le fichier " << path << endl;
      exit(0);
   }

   return texture;
}

Texture FilesManager::loadActivityIcon(const string activity_file_name)
{
   return loadImgTexture(activity_file_name + "/icon.png");
}
