#pragma once
#include "tools.h"
#include "BlockText.h"
//Macro pour les caractéristiques du pnj
#define ANIM_SPEED 0.08f
#define PNJ_SCALE 1.0f
#define PNJ_LENGTH 14*PNJ_SCALE
#define PNJ_HEIGHT 31*PNJ_SCALE

int framepnjX;
int framepnjY; 
sfVector2f pnjPos;

//Prototype des fonctions utilisé dans pnj.c
void initPnj(); 
void updatePnj();
void displayPnj(sfRenderWindow* _window); 
