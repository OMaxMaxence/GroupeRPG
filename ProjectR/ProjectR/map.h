#pragma once
#include "tools.h"

//Macro pour les textures
#define T_VIDE (sfIntRect){0,0,32,32}
#define T_HERBECLAIR (sfIntRect){32,0,32,32}
#define T_TERRE (sfIntRect){64,0,32,32}
#define T_BOIS (sfIntRect){96,0,32,32}
#define T_EAUCLAIR (sfIntRect){ 128,0,32,32}
#define T_ARBRECLAIR (sfIntRect){160,0,32,32}
#define T_PIERRE (sfIntRect){192,0,32,32}
#define T_COFFRE (sfIntRect){224,0,32,32}
#define T_PORTE (sfIntRect){256,0,32,32} 
#define T_PNJ (sfIntRect){288,0,32,32} 
#define T_DRAPEAU (sfIntRect){320,0,32,32}
#define T_HERBEFONCE (sfIntRect){352,0,32,32}
#define T_ARBREFONCE (sfIntRect){384,0,32,32}
#define T_EAUFONCE (sfIntRect){416,0,32,32}
//Macro taille de map
#define MAP_HEIGHT 75
#define MAP_LENGTH 100

char tileMap[MAP_HEIGHT][MAP_LENGTH];
sfVector2f tilePos;
sfSprite* tileSpriteMap;

//Direction du player
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
void updateMap(sfRenderWindow* _window, sfView* _view);
void updateGameMap(sfRenderWindow* _window, sfView* _view);
void displayMap(sfRenderWindow* _window);  
void displayGameMap(sfRenderWindow* _window);