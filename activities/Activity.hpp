#pragma once

#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <opencv2/core/mat.hpp>

class Activity
{
public:
   /* Lancer l'activité */
   virtual void run(cv::Mat frame) = 0;

   /* Proposer un event à récuperer. Si l'event est récupéré, on renvoie vrai */
   virtual bool catchEvent(sf::Event event) = 0;

   /* Proposer un event à récuperer. Si l'event est récupéré, on renvoie vrai */
   virtual std::vector<std::unique_ptr<sf::Drawable>> getDrawables() const = 0;

protected:
   Activity(const sf::Vector2u window_size) : _window_size(window_size) {}
   
   sf::Vector2f getWindowPos(const sf::Vector2f pos, const sf::Vector2u frame_size) const;

   const sf::Vector2u _window_size;
   cv::Mat _last_frame;
};