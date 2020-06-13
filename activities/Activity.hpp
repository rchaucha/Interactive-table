#pragma once

#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Activity
{
public:
   /* Lancer l'activité */
   virtual void run(cv::Mat frame) = 0;

   /* Proposer un event à récuperer. Si l'event est récupéré, on renvoie vrai */
   virtual bool catchEvent(sf::Event event) = 0;

   /* Proposer un event à récuperer. Si l'event est récupéré, on renvoie vrai */
   virtual std::vector<sf::Drawable> getDrawables(sf::Event event) = 0;

};