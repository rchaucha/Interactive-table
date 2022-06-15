#include "SFMLMenu.hpp"

#include <tools\FilesManager.hpp>
#include <SFML/Window/Event.hpp>
#include "activities\ActivityLogic.hpp"
#include "activities/NoneActivity.hpp"
#include "commands/OpenAppCommand.hpp"
#include "commands/CloseAppCommand.hpp"


void SFMLMenu::draw(sf::RenderWindow& window) const
{
   const auto w_size = window.getSize();

   const float but_size =  w_size.y / 17.f,    // taille des boutons
         space_size = but_size / 4.f;          // taille des espaces entre les boutons

   const std::size_t nbr_of_but = getNbrButtonsOnCurrentPage();
   const unsigned int nbr_of_but_on_first_line = std::min((unsigned int)nbr_of_but, BUTTONS_PER_ROW),
         nbr_of_lines = (unsigned int)ceil(nbr_of_but / 3.f);

   const float menu_width = nbr_of_but_on_first_line * but_size + (nbr_of_but_on_first_line - 1) * space_size;
   const float menu_height = nbr_of_lines * but_size + (nbr_of_lines - 1) * space_size;

   float x = (w_size.x - menu_width) / 2.f;
   float y = (w_size.y - menu_height) / 2.f;
   const float x0 = x;

   for (unsigned int i = 1; const auto& b : getCurrentConstButtons())
   {
      b->setPosition(x, y);
      b->setSize(sf::Vector2f(but_size, but_size));

      sf::RectangleShape rect(*b);

      rect.setTexture(&b->getButtonTexture());    // peut être changé avec une aggrégation d'un rect au lieu d'un héritage (bouton non graphique avec une composante graphique)
      
      rect.setOutlineThickness(1.f);
      rect.setOutlineColor(sf::Color::White);

      window.draw(rect);

      if (i % BUTTONS_PER_ROW == 0)  // on revient à la ligne
      {
         x = x0;
         y += but_size + space_size;
      }
      else
         x += but_size + space_size;

      ++i;
   }
}

bool SFMLMenu::catchEvent(sf::Event event) const
{
   if (event.type == sf::Event::MouseButtonPressed)
   {
      for (const auto& b : getCurrentButtons())
      {
         if (b->isSelected(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y)))
         {
            b->execute();
            return true;
         }
      }
   }

   return false;
}

void SFMLMenu::addActivity(std::shared_ptr<ActivityLogic> activity)
{
   addActivity(activity, _buttons.size());
}

void SFMLMenu::addActivity(std::shared_ptr<ActivityLogic> activity, std::size_t index)
{
   sf::Texture icon = FilesManager::loadActivityIcon(activity->getFolderName());

   auto new_button = std::make_shared<SFMLSquareButton>(new OpenAppCommand(index, activity, this), icon);

   if (index == _buttons.size() || _buttons.size() == 0)
      _buttons.push_back(new_button);
   else
      _buttons.insert(_buttons.begin() + index, new_button);
}

void SFMLMenu::openActivity(std::shared_ptr<ActivityLogic> activity, const std::size_t button_index)
{
   auto it = _buttons.begin() + button_index;

   _buttons.erase(it);

   auto close_button = std::make_shared<SFMLSquareButton>(new CloseAppCommand(button_index, activity, this), FilesManager::loadImgTexture("close.png"));
   auto b_to_insert = activity->getView()->getMenuButtons();

   _buttons.insert(_buttons.begin() + button_index, b_to_insert.begin(), b_to_insert.end());
   _buttons.insert(_buttons.begin() + button_index + b_to_insert.size(), close_button);
}

void SFMLMenu::closeActivity(std::shared_ptr<ActivityLogic> activity, const std::size_t button_index)
{
   size_t nbr_buttons = activity->getView()->getMenuButtons().size() + 1;  // on ajoute le bouton close

   auto it = _buttons.begin() + button_index;

   _buttons.erase(it, it + nbr_buttons);

   // on remet en place le laucher
   addActivity(activity, button_index);
}

std::vector<std::shared_ptr<SFMLSquareButton>> SFMLMenu::getCurrentButtons() const
{
   if (_buttons.size() == 0)
      return std::vector<std::shared_ptr<SFMLSquareButton>>();

   auto first_of_page = _buttons.begin() + getFirstIndexOfPage();
   std::size_t ind_first_of_page = distance(_buttons.begin(), first_of_page);
   std::size_t nbr_buttons_on_page = _buttons.size() - getFirstIndexOfPage();

   std::vector<std::shared_ptr<SFMLSquareButton>> page_vector;

   for (std::size_t i = 0; i < nbr_buttons_on_page; i++)
      page_vector.push_back(_buttons[ind_first_of_page + i]);

   return page_vector;
}