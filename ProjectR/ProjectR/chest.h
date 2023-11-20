#pragma once
#include "tools.h"

typedef struct allChests allChests;
struct allChests
{
	int chestCode;
	sfSprite* chestSprite;
	sfTexture* chestTexture;
	sfVector2f chestPos;
	sfIntRect chestRect;
	sfBool openChest;
};
allChests chests[3];

void initChest();
void updateChest();
void displayChest(sfRenderWindow* _window);