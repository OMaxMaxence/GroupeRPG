#pragma once
#include "tools.h"

#define ANIM_SPEED 0.08f
#define PNJ_SCALE 1.0f
#define PNJ_LENGTH 14*PNJ_SCALE
#define PNJ_HEIGHT 31*PNJ_SCALE

int framepnjX;
int framepnjY; 
sfVector2f pnjpos;


void initPnj(); 
void updatePnj(); 
void displayPnj(sfRenderWindow* _window); 
