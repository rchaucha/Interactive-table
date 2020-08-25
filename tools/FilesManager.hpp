#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

class FilesManager
{
public:
   static sf::Texture loadImgTexture(const std::string path);

   static sf::Texture loadActivityIcon(const std::string activity_file_name);

private:
   static const std::string FILES_PATH;
};
