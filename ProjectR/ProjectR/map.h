#pragma once
#include "tools.h"

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