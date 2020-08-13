#pragma once

#include <gui\SFMLButton.hpp>
#include <gui\SFMLMenu.hpp>

class MenuProxy
{
public:
   MenuProxy(SFMLMenuModel* menu): _menu(menu) {}
   ~MenuProxy() { _menu = nullptr; }

   bool addButton(const unsigned int ID, SFMLButton &b);

private:
   SFMLMenuModel* _menu;
};

