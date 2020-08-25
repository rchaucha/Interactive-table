#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFMLClickableSquare.hpp"

class Activity;

class SFMLMenu
{
public:
   typedef enum ActionType { APP_LAUNCHER, APP_CLOSER, BUTTON, NONE } ActionType;

   typedef struct LastAction 
   {
      ActionType type = NONE;
      std::shared_ptr<SFMLClickableSquare> element_clicked;
   } LastAction;

   bool isLastPage() { return (_buttons.size() / BUTTONS_PER_PAGE == _current_page_nbr); } const
   
   void constexpr nextPage() noexcept { _current_page_nbr++; }

   void draw(sf::RenderWindow& window) const;
   bool catchEvent(sf::Event event);

   void addActivity(std::shared_ptr<Activity> activity, int index = -1);

   LastAction& getLastAction() { return _last_action; }

private:
   class SFMLAppLauncher;
   class SFMLAppCloser;

   void openActivity(SFMLClickableSquare& launcher);
   void closeActivity(SFMLClickableSquare& closer);
   std::vector<std::shared_ptr<SFMLClickableSquare>> getCurrentButtons() const;
   const std::vector<std::shared_ptr<SFMLClickableSquare>> getCurrentConstButtons() const;
   unsigned int getFirstIndexOfPage() const { return BUTTONS_PER_PAGE * _current_page_nbr; }
   std::vector<std::shared_ptr<SFMLClickableSquare>>::iterator findClickableSquare(SFMLClickableSquare& launcher);

   // Nombre de boutons sur une ligne / colonne
   static const unsigned int BUTTONS_PER_ROW = 3;
   static constexpr unsigned int BUTTONS_PER_PAGE = BUTTONS_PER_ROW * BUTTONS_PER_ROW;

   // Page courante, la première est la page 0
   unsigned short _current_page_nbr;

   LastAction _last_action;

   std::vector<std::shared_ptr<SFMLClickableSquare>> _buttons;
};
