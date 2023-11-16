#pragma once
#include "tools.h"
sfMusic* musicMenu;
sfMusic* musicEdit;
sfMusic* musicJouer;

void initMenu();
void updateMenu(sfRenderWindow* _window, sfView* _view);
void displayMenu(sfRenderWindow* _window);

