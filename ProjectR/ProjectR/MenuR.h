#pragma once
#include "tools.h"
sfBool editeur;
int musiqueJouer;
float delai_menu;
float delai_menuJouer;

//prototype fonction
void initMenu();
void updateMenu(sfRenderWindow* _window, sfView* _view);
void displayMenu(sfRenderWindow* _window);

