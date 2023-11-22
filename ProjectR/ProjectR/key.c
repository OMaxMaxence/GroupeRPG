#include "key.h"

sfSprite* key_sprite_create;
sfTexture* key_texture_create;
sfFloatRect rectKey;
sfIntRect iRectKey = { 0,0,32,32 };
sfVector2f keyPos = { 0.0f, 0.0f };

//Fonction initialisation
void initKey()
{
	//Création des 3 sprites de clés et application texture
	for (int i = 0; i < 3; i++)
	{
		keys[i].keyRect.width = 32;
		keys[i].keyRect.height = 32;
		keys[i].keyRect.top = 32;
		keys[i].keyRect.left = i * 32;
		keys[i].keySprite = sfSprite_create();
		keys[i].keyTexture = sfTexture_createFromFile(TEXTURE_PATH"tilesetKEY.png", NULL);
		sfSprite_setTexture(keys[i].keySprite, keys[i].keyTexture, sfTrue);
		sfSprite_setTextureRect(keys[i].keySprite, keys[i].keyRect);
		sfSprite_setScale(keys[i].keySprite, vector2f(0.5f, 0.5f));
		sfSprite_setPosition(keys[i].keySprite, keyPos);
	}
}

//Fonction mise à jour
void updateKey()
{
	//Affichage des clés en inventaire
	for (int i = 0; i < 3; i++)
	{
		// Recupere la position des cles
		keys[i].keyPosStruct.x = keyPos.x + (i*16.0f);
		keys[i].keyPosStruct.y = keyPos.y;
		sfSprite_setTextureRect(keys[i].keySprite, keys[i].keyRect);
		sfSprite_setPosition(keys[i].keySprite, vector2f(keys[i].keyPosStruct.x - 115.0f, keys[i].keyPosStruct.y - 85.0f));


		// Ajout à l'inventaire du joueur quand coffre ouvert
		if (chests[i].isOpen == sfTrue)
		{
			keys[i].keyRect.top = 0;
			keys[i].keyRect.width = 32;
			keys[i].keyRect.height = 32;
			keys[i].keyRect.left = i * 32;
			sfSprite_setTextureRect(keys[i].keySprite, keys[i].keyRect);
			sfSprite_setPosition(keys[i].keySprite, vector2f(keys[i].keyPosStruct.x - 115.0f, keys[i].keyPosStruct.y - 85.0f));
		}
		// Inventaire de clé vide
		else
		{
			keys[i].keyRect.top = 32;
			keys[i].keyRect.width = 32;
			keys[i].keyRect.height = 32;
			keys[i].keyRect.left = i * 32;
			sfSprite_setTextureRect(keys[i].keySprite, keys[i].keyRect);
			sfSprite_setPosition(keys[i].keySprite, vector2f(keys[i].keyPosStruct.x - 115.0f, keys[i].keyPosStruct.y - 85.0f));
		}

		
	
	}
}

//Fonction affichage
void displayKey(sfRenderWindow* _window)
{
	for (int i = 0; i < 3; i++)
	{
		sfRenderWindow_drawSprite(_window, keys[i].keySprite, NULL);
	}
}
