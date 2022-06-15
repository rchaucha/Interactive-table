#pragma once
#include <unordered_map>
#include <memory>
#include <SFML/Audio/Music.hpp>

class AudioPlayer
{
public:
   static bool playSound(const std::string& activity_file_name, const std::string& file_name, float volume = 100, bool loop = false);

private:
   //static std::unordered_map<const std::string, std::unique_ptr<sf::Music>> _musics_by_names;

};

