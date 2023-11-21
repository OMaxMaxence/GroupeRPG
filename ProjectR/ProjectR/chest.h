#pragma once
#include "tools.h"

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

void initChest();
void updateChest();
void displayChest(sfRenderWindow* _window);