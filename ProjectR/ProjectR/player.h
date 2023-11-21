#pragma once

#include "tools.h"

#define ANIM_SPEED 0.08f
#define PLAYER_SCALE 1.0f
#define PLAYER_LENGTH 17*PLAYER_SCALE
#define PLAYER_HEIGHT 23*PLAYER_SCALE
#define PLAYER_SPEED 100.0f

int frameX;
int frameY;
sfVector2f playerPos;
sfVector2f playerSpeed;
sfSprite* player;

//typedef enum Direction Direction;
//enum Direction {BAS = 0, DROITE, GAUCHE, HAUT};



void initPlayer();
void updatePlayer();
void displayPlayer(sfRenderWindow* _window);
