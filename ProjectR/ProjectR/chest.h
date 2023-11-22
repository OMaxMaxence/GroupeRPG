#pragma once
#include "tools.h"

//Structure pour créer les coffres
typedef struct allChests allChests;
struct allChests
{
	sfSprite* chestSprite;
	sfTexture* chestTexture;
	sfVector2f chestPos;
	sfIntRect chestRect;
	sfBool openChest;
	sfBool isOpen;
};
allChests chests[3];

//prototype fonction
void initChest();
void updateChest();
void displayChest(sfRenderWindow* _window);