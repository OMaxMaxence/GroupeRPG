#pragma once
#include "tools.h"

int nb_key;
int frameKeyX;
int frameKeyY;


typedef struct allKeys allKeys;
struct allKeys
{
	sfSprite* keySprite;
	sfTexture* keyTexture;
	sfVector2f keyPosStruct;
	sfIntRect keyRect;
};
allKeys keys[3];

sfVector2f keyPos;

//prototype fonction
void initKey();
void updateKey();
void displayKey(sfRenderWindow* _window);