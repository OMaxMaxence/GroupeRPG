#pragma once
#include "tools.h"

//Macro pour raccourci des textures
#define TEXTURE_PATH "../Ressources/Textures/"
#define T_VIDE (sfIntRect){0,0,32,32}
#define T_HERBE (sfIntRect){32,0,32,32}
#define T_TERRE (sfIntRect){64,0,32,32}
#define T_BOIS (sfIntRect){96,0,32,32}
#define T_EAU (sfIntRect){ 128,0,32,32}
#define T_ARBRE (sfIntRect){160,0,32,32}
#define T_PIERRE (sfIntRect){192,0,32,32}
#define T_COFFRE (sfIntRect){224,0,32,32}
#define T_DRAPEAU (sfIntRect){256,0,32,32} 
#define T_PNJ (sfIntRect){288,0,32,32} 
#define T_FERMER (sfIntRect){0,0,32,32}
#define T_QUART (sfIntRect){32,0,32,32}
#define T_DEMI (sfIntRect){64,0,32,32}
#define T_OUVERT (sfIntRect){ 96,0,32,32}
//Macro pour la taille de map
#define MAP_HEIGHT 75
#define MAP_LENGTH 100

typedef enum
{
	BAS = 0,
	DROITE,
	GAUCHE,
	HAUT
}Direction;



//Prototype des fonctions utilisées dans map.c
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse);

void initMap();
void updateMap(sfRenderWindow* _window, float _t, sfView* _view);
void updateGameMap(sfRenderWindow* _window, float _t, sfView* _view);
void displayMap(sfRenderWindow* _window, float _t);
void displayGameMap(sfRenderWindow* _window, float _t);