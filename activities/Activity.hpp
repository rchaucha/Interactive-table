#pragma once

#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <opencv2/core/mat.hpp>
#include <gui\menu\SFMLButton.hpp>

class Activity : public std::enable_shared_from_this<Activity>
{
public:
   virtual void run(cv::Mat frame) = 0;
   
   virtual void update(cv::Mat frame) = 0;

   // Proposer un event à récuperer. Si l'event est récupéré, on renvoie vrai
   virtual bool catchEvent(sf::Event event) = 0;

   virtual void buttonClicked(std::string button_id) = 0;

   virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables() const = 0;

   virtual std::vector<std::shared_ptr<SFMLButton>> getButtons() = 0;
   virtual std::string getFolderName() const = 0;

   virtual const unsigned int getId() const noexcept final { return _ID; }

  // virtual std::shared_ptr<Activity> makeUniqueActivity() const = 0;
   bool operator==(const Activity& other);


protected:
   Activity(const sf::Vector2u window_size, const sf::Vector2u frame_size);
   Activity(const Activity& orig) = delete;

   // Convertit des coordonnées (nbr de pixels) de l'espace de la camera à celui de la fenêtre
   sf::Vector2f frame2Window(const sf::Vector2f frame_coordinates) const;

   const sf::Vector2u _window_size;
   const sf::Vector2u _frame_size;
   cv::Mat _last_frame;

   const unsigned int _ID;
   static unsigned int _id_generator;
};