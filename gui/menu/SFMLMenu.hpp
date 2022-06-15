#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFMLSquareButton.hpp"

class ActivityLogic;

class SFMLMenu
{
public:
   bool isLastPage() const noexcept { return (_buttons.size() / BUTTONS_PER_PAGE == _current_page_nbr); }
   
   void constexpr nextPage() noexcept { _current_page_nbr++; }

   void draw(sf::RenderWindow& window) const;
   bool catchEvent(sf::Event event) const;

   void addActivity(std::shared_ptr<ActivityLogic> activity);
   void openActivity(std::shared_ptr<ActivityLogic> activity, const std::size_t button_index);
   void closeActivity(std::shared_ptr<ActivityLogic> activity, const std::size_t button_index);

private:
   void addActivity(std::shared_ptr<ActivityLogic> activity, std::size_t index);
   std::vector<std::shared_ptr<SFMLSquareButton>> getCurrentButtons() const;
   const std::vector<std::shared_ptr<SFMLSquareButton>> getCurrentConstButtons() const { return getCurrentButtons(); }
   const std::size_t getNbrButtonsOnCurrentPage() const { return getCurrentConstButtons().size(); }
   unsigned int getFirstIndexOfPage() const { return BUTTONS_PER_PAGE * _current_page_nbr; }
   
   // Nombre de boutons sur une ligne / colonne
   static const unsigned int BUTTONS_PER_ROW = 3;
   static constexpr unsigned int BUTTONS_PER_PAGE = BUTTONS_PER_ROW * BUTTONS_PER_ROW;

   // Page courante, la première est la page 0
   unsigned short _current_page_nbr = 0;

   std::vector<std::shared_ptr<SFMLSquareButton>> _buttons;
};
