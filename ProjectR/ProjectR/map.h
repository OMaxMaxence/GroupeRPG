#pragma once
#include "tools.h"

#define MAP_HEIGHT 75
#define MAP_LENGTH 100

typedef enum
{
	BAS = 0,
	DROITE,
	GAUCHE,
	HAUT
}Direction;




sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse);


void initMap();
void updateMap(sfRenderWindow* _window, float _t, sfView* _view);
void displayMap(sfRenderWindow* _window, float _t);