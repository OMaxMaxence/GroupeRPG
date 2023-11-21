#pragma once
#include "tools.h"

typedef struct allPortes allPortes;
struct allPortes
{
	int porteCode;
	sfSprite* porteSprite;
	sfTexture* porteTexture;
	sfVector2f portePos;
	sfIntRect porteRect;
	sfBool openPorte;
};
allPortes portes; 

void initPorte();
void updatePorte();
void displayPorte(sfRenderWindow* _window);