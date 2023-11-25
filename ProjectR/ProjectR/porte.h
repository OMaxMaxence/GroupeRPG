#pragma once
#include "tools.h"

//Structure pour créer les portes (possibilté d'ajouter des portes plus facilement)
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

//prototype fonction
void initPorte();
void updatePorte();
void displayPorte(sfRenderWindow* _window);