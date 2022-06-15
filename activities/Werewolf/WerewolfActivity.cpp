#include "activities/Werewolf/WerewolfActivity.hpp"

#include <time.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include "tools/AudioPlayer.hpp"


WerewolfActivity::WerewolfActivity(WerewolfActivityView* view):
   _view(view)
{
   _view->setActivityLogic(this);
}

WerewolfActivity::~WerewolfActivity()
{
   delete _view;
}

void WerewolfActivity::run()
{
   // Lancement de la musique d'ambiance
   AudioPlayer::playSound(getFolderName(), "music.ogg");
   
   // Lancement de la voix d'introduction au jeu
   AudioPlayer::playSound(getFolderName(), "game_launch.ogg");
}

void WerewolfActivity::update()
{
   
}