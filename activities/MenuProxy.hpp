#pragma once

#include <gui\SFMLButton.hpp>
#include <gui\SFMLMenu.hpp>

class MenuProxy
{
public:
   MenuProxy(SFMLMenu* menu): _menu(menu) {}
   ~MenuProxy() { _menu = nullptr; }

   bool addButton(const long ID, SFMLButton &b);
   bool removeButton(const long ID, SFMLButton &b);

private:
   SFMLMenu* _menu;
};

