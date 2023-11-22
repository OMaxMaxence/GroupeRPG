#include "chest.h"


float chestTimer = 0.0f;
float distToPlayer = 0.0f;

//Fonction initialisation
void initChest()
{
	//Création des 3 sprites de coffres et application texture
	for (int i = 0; i < 3; i++)
	{
		//chests[i].chestPos.x = 30.0f + i*32*2;
		//chests[i].chestPos.y = 100.0f;
		chests[i].chestRect.width = 32;
		chests[i].chestRect.height = 32;
		chests[i].chestRect.top = 0;
		chests[i].chestRect.left = 0;
		chests[i].openChest = sfFalse;
		chests[i].isOpen = sfFalse;
		chests[i].chestSprite = sfSprite_create();
		chests[i].chestTexture = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
		sfSprite_setTexture(chests[i].chestSprite, chests[i].chestTexture, sfTrue);
		sfSprite_setTextureRect(chests[i].chestSprite, chests[i].chestRect);
		sfSprite_setPosition(chests[i].chestSprite, chests[i].chestPos);
		sfSprite_setOrigin(chests[i].chestSprite, vector2f(16.0f, 16.0f));
	}
}

//Fonction mise à jour

void updateChest()
{
	chestTimer += getDeltaTime();
	nb_key = 0;

	for (int  i = 0; i < 3; i++)
	{
		//Detection de la distance entre le player et le coffre
		distToPlayer = distanceBetweenTwoPoints(chests[i].chestPos, playerPos);
		//Bouton interaction
		if (sfKeyboard_isKeyPressed(sfKeySpace) && distToPlayer < 40.0f)
		{
			chests[i].openChest = sfTrue;
		}
		//Animation du coffre
		if (chestTimer > 1.0f && chests[i].openChest == sfTrue && chests[i].chestRect.left < 96)
		{
			chests[i].chestRect.left += 32;
			sfSprite_setTextureRect(chests[i].chestSprite, chests[i].chestRect);
			sfSprite_setPosition(chests[i].chestSprite, chests[i].chestPos);
			chestTimer = 0;
		}
		//Obtention de la clé
		if (chests[i].chestRect.left >= 96)
		{
			chests[i].isOpen = sfTrue;
			nb_key += 1;
		}
	}

}

//Fonction affichage
void displayChest(sfRenderWindow* _window)
{
	for (int i = 0; i < 3; i++)
	{
		sfRenderWindow_drawSprite(_window, chests[i].chestSprite, NULL);
	}
}
