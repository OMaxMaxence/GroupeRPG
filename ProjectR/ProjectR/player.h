#pragma once

#include "tools.h"
// Macro pour les caract�ristiques du player
#define ANIM_SPEED 0.08f
#define PLAYER_SCALE 1.0f
#define PLAYER_LENGTH 17*PLAYER_SCALE
#define PLAYER_HEIGHT 23*PLAYER_SCALE
#define PLAYER_SPEED 130.0f

int frameX;
int frameY;
sfVector2f playerPos;
sfVector2f playerSpeed;
sfSprite* player;



//prototype fonction
void initPlayer();
void updatePlayer();
void displayPlayer(sfRenderWindow* _window);
sfBool showSpacebar();
