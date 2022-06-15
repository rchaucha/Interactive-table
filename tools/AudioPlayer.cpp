#include "AudioPlayer.hpp"
#include "tools/FilesManager.hpp"

//std::unordered_map<const std::string, std::unique_ptr<sf::Music>> AudioPlayer::_musics_by_names;

bool AudioPlayer::playSound(const std::string& activity_file_name, const std::string& file_name, float volume, bool loop)
{
   /*_musics_by_names[file_name] = std::make_unique<sf::Music>();

   if (!_musics_by_names[file_name]->openFromFile(FilesManager::getSoundFilepath(activity_file_name, file_name)))
      return false;

   _musics_by_names[file_name]->setVolume(volume);
   _musics_by_names[file_name]->setLoop(loop);

   _musics_by_names[file_name]->play();
   */
   return true;
}
