#include "WerewolfActivityView.hpp"

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

#include "tools\FilesManager.hpp"
#include "activities/Werewolf/WerewolfActivity.hpp"
#include "commands/ResetTrackersCommand.hpp"
#include "gui\menu\SFMLSquareButton.hpp"

WerewolfActivityView::WerewolfActivityView(const sf::Vector2u window_size, const sf::Vector2u frame_size):
   ActivityView(window_size, frame_size)
{}

WerewolfActivityView::~WerewolfActivityView()
{
   delete _activity;
}

bool WerewolfActivityView::catchEvent(sf::Event event) const
{
   return false;
}

std::vector<std::shared_ptr<sf::Drawable>> WerewolfActivityView::getDrawables() const
{
   std::vector<std::shared_ptr<sf::Drawable>> drawables;

   return drawables;
}

std::vector<std::shared_ptr<SFMLSquareButton>> WerewolfActivityView::getMenuButtons() const
{
   std::vector<std::shared_ptr<SFMLSquareButton>> buttons;
   sf::Texture texture = FilesManager::loadImgTexture(_activity->getFolderName() + "/reset.png");

  // buttons.push_back(std::make_shared<SFMLSquareButton>(new ResetTrackersCommand(_activity), texture));

   return buttons;
}
