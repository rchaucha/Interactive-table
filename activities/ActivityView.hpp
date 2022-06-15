#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <gui\menu\SFMLSquareButton.hpp>
#include <vector>

class ActivityView
{
public:
   ActivityView(const sf::Vector2u window_size, const sf::Vector2u frame_size) :
      _window_size(window_size),
      _frame_size(frame_size) 
   {}

   // Proposer un event � r�cuperer. Si l'event est r�cup�r�, on renvoie vrai
   virtual bool catchEvent(sf::Event event) const = 0;

   virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables() const = 0;

   virtual std::vector<std::shared_ptr<SFMLSquareButton>> getMenuButtons() const = 0;
   
protected:   
   // Convertit des coordonn�es (nbr de pixels) de l'espace de la camera � celui de la fen�tre
   sf::Vector2f frame2Window(const sf::Vector2f frame_coordinates) const;

   const sf::Vector2u _window_size;
   const sf::Vector2u _frame_size;
};

