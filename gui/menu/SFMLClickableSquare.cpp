#include "SFMLClickableSquare.hpp"

#include "activities\Activity.hpp"
#include "activities\NoneActivity.hpp"

using namespace sf;
using namespace std;

unsigned int SFMLClickableSquare::_id_generator = 0;

SFMLClickableSquare::SFMLClickableSquare(shared_ptr<Activity> activity, const Texture texture, Vector2f pos, Vector2f size) :
   RectangleShape(size),
   _activity(activity),
   _texture(texture),
   _ID(_id_generator)
{
   _id_generator++;
   setPosition(pos);
   setTexture(&_texture);
}

SFMLClickableSquare::SFMLClickableSquare(std::shared_ptr<Activity> activity, sf::Texture texture):
   SFMLClickableSquare(activity, texture, Vector2f(0, 0), Vector2f(0, 0))
{}

bool SFMLClickableSquare::isSelected(const Vector2f mouse_pos) const
{
   return getGlobalBounds().contains(mouse_pos);
}

shared_ptr<Activity> SFMLClickableSquare::getActivity() noexcept
{
   if (_activity == nullptr)
      _activity = make_shared<NoneActivity>();

   return _activity;
}

bool SFMLClickableSquare::operator==(const SFMLClickableSquare& other)
{
   return other._ID == _ID;
}