#include "SFMLMenu.hpp"

#include <tools\FilesManager.hpp>
#include <SFML/Window/Event.hpp>
#include "activities\Activity.hpp"
#include "activities/NoneActivity.hpp"

using namespace std;
using namespace sf;


class SFMLMenu::SFMLAppLauncher : public SFMLClickableSquare
{
public:
   SFMLAppLauncher(shared_ptr<Activity> activity, Texture texture) :
      SFMLClickableSquare(activity, texture)
   {}
};

class SFMLMenu::SFMLAppCloser : public SFMLClickableSquare
{
public:
   SFMLAppCloser(shared_ptr<Activity> activity) :
      SFMLClickableSquare(activity, FilesManager::loadImgTexture("close.png"))
   {}
};

void SFMLMenu::draw(RenderWindow& window) const
{
   auto w_size = window.getSize();

   float but_size = BUTTONS_PER_ROW * w_size.y / 50.f;    // taille des boutons
   float space_size = (BUTTONS_PER_ROW - 1) * but_size / 4.f;   // taille des espaces entre les boutons

   float y = (w_size.y - but_size - space_size) / 2.f;
   float x = (w_size.x - but_size - space_size) / 2.f;
   const float x0 = x;

   sf::RectangleShape* rect;

   unsigned int i = 1;
   for (const auto& b : getCurrentConstButtons())
   {
      b->setPosition(x, y);
      b->setSize(Vector2f(but_size, but_size));

      rect = new RectangleShape(*b);

      rect->setTexture(&b->getButtonTexture());    // peut être changé avec une aggrégation d'un rect au lieu d'un héritage (bouton non graphique avec une composante graphique)
      
      rect->setOutlineThickness(1.f);
      rect->setOutlineColor(sf::Color::White);

      window.draw(*rect);

      if (i % BUTTONS_PER_ROW == 0)  // on revient à la ligne
      {
         x = x0;
         y += but_size + space_size;
      }
      else
         x += but_size + space_size;

      i++;
   }
}

bool SFMLMenu::catchEvent(Event event)
{
   if (event.type == sf::Event::MouseButtonPressed)
   {
       for (auto& b : getCurrentButtons())
      {
         if (b->isSelected(Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y)))
         {
            _last_action.element_clicked = b;

            if (typeid(*b) == typeid(SFMLAppLauncher))
            {
               openActivity(*b);
               _last_action.type = ActionType::APP_LAUNCHER;
            }

            else if (typeid(*b) == typeid(SFMLAppCloser))
            {
               closeActivity(*b);
               _last_action.type = ActionType::APP_CLOSER;
            }

            else if (typeid(*b) == typeid(SFMLButton))
               _last_action.type = ActionType::BUTTON;

            return true;
         }
      }
   }

   return false;
}

void SFMLMenu::addActivity(shared_ptr<Activity> activity, int index)
{
   Texture icon = FilesManager::loadActivityIcon(activity->getFolderName());
   
   if (index == -1 || _buttons.size() == 0)
      _buttons.push_back(make_shared<SFMLAppLauncher>(activity, icon));
   else
      _buttons.insert(_buttons.begin() + index, make_shared<SFMLAppLauncher>(activity, icon));
}

void SFMLMenu::openActivity(SFMLClickableSquare& launcher)
{
   auto it = findClickableSquare(launcher);
   int ind = distance(_buttons.begin(), it);

   _buttons.erase(it);

   auto close_button = std::make_shared<SFMLAppCloser>(launcher.getActivity());
   auto b_to_insert = launcher.getActivity()->getButtons();

   _buttons.insert(_buttons.begin() + ind, b_to_insert.begin(), b_to_insert.end());
   _buttons.insert(_buttons.begin() + ind + b_to_insert.size(), close_button);
}

void SFMLMenu::closeActivity(SFMLClickableSquare& closer)
{
   auto it = findClickableSquare(closer);
   int ind = distance(_buttons.begin(), it);
   size_t nbr_buttons = closer.getActivity()->getButtons().size();

   _buttons.erase(it - nbr_buttons, it + 1);

   // on remet en place le laucher
   addActivity(closer.getActivity(), ind);
}

vector<shared_ptr<SFMLClickableSquare>> SFMLMenu::getCurrentButtons() const
{
   if (_buttons.size() == 0)
      return vector<shared_ptr<SFMLClickableSquare>>();

   auto first_of_page = _buttons.begin() + getFirstIndexOfPage();
   unsigned int ind_first_of_page = distance(_buttons.begin(), first_of_page);
   unsigned int nbr_buttons_on_page = _buttons.size() - getFirstIndexOfPage();

   vector<shared_ptr<SFMLClickableSquare>> page_vector;

   for (unsigned int i = 0; i < nbr_buttons_on_page; i++)
      page_vector.push_back(_buttons[ind_first_of_page + i]);

   return page_vector;
}

const vector<shared_ptr<SFMLClickableSquare>> SFMLMenu::getCurrentConstButtons() const
{
   return getCurrentButtons();
}

std::vector<std::shared_ptr<SFMLClickableSquare>>::iterator SFMLMenu::findClickableSquare(SFMLClickableSquare& launcher)
{
   auto it = _buttons.begin();
   for (; it < _buttons.end(); it++)
      if (launcher == **it)
         break;

   return it;
}
