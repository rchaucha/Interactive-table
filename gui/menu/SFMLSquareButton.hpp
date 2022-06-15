#pragma once

#include "SFMLButton.hpp"

#include <memory>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class ActivityLogic;

class SFMLSquareButton : public SFMLButton, public sf::RectangleShape
{
public:
   SFMLSquareButton(const Command* command, sf::Texture texture, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(0, 0));

   bool isSelected(const sf::Vector2f mouse_pos) const override;

   const sf::Texture& getButtonTexture() const noexcept { return _texture; }
   void setButtonTexture(sf::Texture& texture) noexcept { _texture = texture; }

protected:
   // Les véritables accesseurs à la texture ne sont utilisable qu'à l'intérieur de la classe
   void setTexture(const sf::Texture* texture) { this->sf::Shape::setTexture(texture); }
   const sf::Texture* getTexture() const { return this->sf::Shape::getTexture(); }

   sf::Texture _texture;
};
