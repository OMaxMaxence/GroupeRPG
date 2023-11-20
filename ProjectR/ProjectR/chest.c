#include "chest.h"

void initChest()
{
	for (int i = 0; i < 3; i++)
	{
		chests[i].chestPos.x = 100.0f + i*32;
		chests[i].chestPos.y = 100.0f;
		chests[i].chestRect.width = 32;
		chests[i].chestRect.height = 32;
		chests[i].chestRect.top = 0;
		chests[i].chestRect.left = 0;
		chests[i].chestCode = 0;
		chests[i].chestSprite = sfSprite_create();
		chests[i].chestTexture = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
		sfSprite_setTexture(chests[i].chestSprite, chests[i].chestTexture, sfTrue);
		sfSprite_setTextureRect(chests[i].chestSprite, chests[i].chestRect);
		sfSprite_setPosition(chests[i].chestSprite, chests[i].chestPos);
	}
}

float chestTimer = 0.0f;
sfBool openChest = sfFalse;
void updateChest()
{
	chestTimer += getDeltaTime();
	for (int  i = 0; i < 3; i++)
	{
		if (sfKeyboard_isKeyPressed(sfKeyJ))
		{
			openChest = sfTrue;
		}
		if (chestTimer > 1.0f && openChest == sfTrue && chests[i].chestRect.left < 96)
		{
			chests[i].chestRect.left += 32;
			sfSprite_setTextureRect(chests[i].chestSprite, chests[i].chestRect);
			sfSprite_setPosition(chests[i].chestSprite, chests[i].chestPos);
			chestTimer = 0;
		}
	}

}

void displayChest(sfRenderWindow* _window)
{
	for (int i = 0; i < 3; i++)
	{
		sfRenderWindow_drawSprite(_window, chests[i].chestSprite, NULL);
	}
}
