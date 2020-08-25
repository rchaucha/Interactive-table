#pragma once

#include "I_SFMLClickable.hpp"

#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class Activity;

class SFMLClickableSquare : public I_SFMLClickable, public sf::RectangleShape
{
public:
   SFMLClickableSquare(std::shared_ptr<Activity> activity, sf::Texture texture, sf::Vector2f pos, sf::Vector2f size);
   SFMLClickableSquare(std::shared_ptr<Activity> activity, sf::Texture texture);

   bool isSelected(const sf::Vector2f mouse_pos) const override;

   std::shared_ptr<Activity> getActivity() noexcept;

   const sf::Texture& getButtonTexture() const noexcept { return _texture; }
   void setButtonTexture(sf::Texture& texture) noexcept { _texture = texture; }

   bool operator==(const SFMLClickableSquare& other);

protected:
   std::shared_ptr<Activity> _activity;

   // Les véritables accesseurs à la texture ne sont utilisable qu'à l'intérieur de la classe
   void setTexture(const sf::Texture* texture) { this->sf::Shape::setTexture(texture); }
   const sf::Texture* getTexture() const { return this->sf::Shape::getTexture(); }

   sf::Texture _texture;

   const unsigned int _ID;
   static unsigned int _id_generator;
};
