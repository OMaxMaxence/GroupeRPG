#pragma once
#include "tools.h"

int nb_key;
int frameKeyX;
int frameKeyY;


typedef struct chests chests;
struct chests
{
	sfSprite* chest;
	int life;
};
chests chest[3];

sfVector2f keyPos;

void initKey();
void updateKey();
void displayKey(sfRenderWindow* _window);