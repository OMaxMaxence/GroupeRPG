#pragma once
#include "tools.h"

//Structure pour cr�er les portes (possibilt� d'ajouter des portes plus facilement)
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