#include "GlassTrackingActivityView.hpp"

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include "tools\FilesManager.hpp"
#include "activities\GlassTracking\GlassTrackingActivity.hpp"
#include "commands/ResetTrackersCommand.hpp"
#include "gui\menu\SFMLSquareButton.hpp"

GlassTrackingActivityView::GlassTrackingActivityView(const sf::Vector2u window_size, const sf::Vector2u frame_size):
   ActivityView(window_size, frame_size)
{}

GlassTrackingActivityView::~GlassTrackingActivityView()
{
   delete _activity;
}

bool GlassTrackingActivityView::catchEvent(sf::Event event) const 
{
   if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
   {
      _activity->resetTrackers();
      return true;
   }
   return false;
}

std::vector<std::shared_ptr<sf::Drawable>> GlassTrackingActivityView::getDrawables() const
{
   std::vector<std::shared_ptr<sf::Drawable>> drawables;
      
   unsigned int roi_ind = 0;

   // Rectangles correspondant aux verres
   for (const auto& rect : *_roi)
   {
      sf::RectangleShape* rectangle = new sf::RectangleShape(frame2Window(sf::Vector2f((float)rect.width, (float)rect.height)));
      rectangle->setPosition(frame2Window(sf::Vector2f((float)rect.x, (float)rect.y)));
      rectangle->setOrigin(frame2Window(sf::Vector2f((float)rect.width / 2, (float)rect.height / 2)));
      rectangle->scale(1.4f, 1.4f);
      rectangle->setOutlineThickness(0);

      if (!_roi_index_to_texture_index.count(roi_ind))   // si la texture n'a pas été chargée
         std::cerr << "Veuillez réinitialiser les trackers";
      else
         rectangle->setTexture(&_texture_container[_roi_index_to_texture_index.at(roi_ind)]);

      drawables.push_back(std::shared_ptr<sf::RectangleShape>(rectangle));

      roi_ind++;
   }

   return drawables;
}

std::vector<std::shared_ptr<SFMLSquareButton>> GlassTrackingActivityView::getMenuButtons() const
{
   std::vector<std::shared_ptr<SFMLSquareButton>> buttons;
   sf::Texture texture = FilesManager::loadImgTexture(_activity->getFolderName() + "/reset.png");

   buttons.push_back(std::make_shared<SFMLSquareButton>(new ResetTrackersCommand(_activity), texture));

   return buttons;
}

void GlassTrackingActivityView::loadTextures()
{
   for (unsigned int i = 1; i <= _NBR_OF_EFFECTS; i++)
      _texture_container.push_back(FilesManager::loadImgTexture(_activity->getFolderName() + "/" + std::to_string(i) + ".png"));
}

void GlassTrackingActivityView::setGlassesTexture()
{
   if (_roi)
   {
      for (unsigned int roi_ind = 0; roi_ind < _roi->size(); roi_ind++)
      {
         int effect_nbr = rand() % _NBR_OF_EFFECTS;

         _roi_index_to_texture_index[roi_ind] = effect_nbr;
      }
   }
}

void GlassTrackingActivityView::update(const std::vector<cv::Rect2d>& roi)
{
   _roi = &roi;

   if (_roi_index_to_texture_index.size() < _roi->size())
      setGlassesTexture();
}
