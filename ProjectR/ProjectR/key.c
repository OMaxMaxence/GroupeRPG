#include "key.h"

sfSprite* key_sprite_create;
sfTexture* key_texture_create;
sfFloatRect rectKey;
sfIntRect iRectKey = { 0,0,32,32 };
sfVector2f keyPos = { 0.0f, 0.0f };


void initKey()
{

	for (int i = 0; i < 3; i++)
	{
		keys[i].keyRect.width = 32;
		keys[i].keyRect.height = 32;
		keys[i].keyRect.top = 32;
		keys[i].keyRect.left = i * 32;
		keys[i].keyCode = 0;
		keys[i].keySprite = sfSprite_create();
		keys[i].keyTexture = sfTexture_createFromFile(TEXTURE_PATH"tilesetKEY.png", NULL);
		sfSprite_setTexture(keys[i].keySprite, keys[i].keyTexture, sfTrue);
		sfSprite_setTextureRect(keys[i].keySprite, keys[i].keyRect);
		sfSprite_setScale(keys[i].keySprite, vector2f(0.5f, 0.5f));
		sfSprite_setPosition(keys[i].keySprite, keyPos);
	}
}

void updateKey()
{
	for (int i = 0; i < 3; i++)
	{
		keys[i].keyPosStruct.x = keyPos.x + (i*16.0f);
		keys[i].keyPosStruct.y = keyPos.y;
		sfSprite_setTextureRect(keys[i].keySprite, keys[i].keyRect);
		sfSprite_setPosition(keys[i].keySprite, vector2f(keys[i].keyPosStruct.x - 115.0f, keys[i].keyPosStruct.y - 85.0f));
		if (sfKeyboard_isKeyPressed(sfKeyU))
		{
			keys[i].keyCode = 1;
		}
		if (sfKeyboard_isKeyPressed(sfKeyI))
		{
			keys[i].keyCode = 2;
		}
		if (sfKeyboard_isKeyPressed(sfKeyO))
		{
			keys[i].keyCode = 3;
		}
		if (sfKeyboard_isKeyPressed(sfKeyP))
		{
			keys[i].keyCode = 0;
		}
		if (keys[i].keyCode == 1)
		{
			keys[0].keyRect.top = 0;
			keys[0].keyRect.width = 32;
			keys[0].keyRect.height = 32;
			keys[0].keyRect.left = 0;
			sfSprite_setTextureRect(keys[0].keySprite, keys[0].keyRect);
			sfSprite_setPosition(keys[0].keySprite, vector2f(keys[0].keyPosStruct.x - 115.0f, keys[0].keyPosStruct.y - 85.0f));
		}
		else if (keys[i].keyCode == 2)
		{
			keys[1].keyRect.top = 0;
			keys[1].keyRect.width = 32;
			keys[1].keyRect.height = 32;
			keys[1].keyRect.left = 32;
			sfSprite_setTextureRect(keys[1].keySprite, keys[1].keyRect);
			sfSprite_setPosition(keys[1].keySprite, vector2f(keys[1].keyPosStruct.x - 115.0f, keys[1].keyPosStruct.y - 85.0f));
		}
		else if (keys[i].keyCode == 3)
		{
			keys[2].keyRect.top = 0;
			keys[2].keyRect.width = 32;
			keys[2].keyRect.height = 32;
			keys[2].keyRect.left = 64;
			sfSprite_setTextureRect(keys[2].keySprite, keys[2].keyRect);
			sfSprite_setPosition(keys[2].keySprite, vector2f(keys[2].keyPosStruct.x - 115.0f, keys[2].keyPosStruct.y - 85.0f));
		}
	
	}
}


void displayKey(sfRenderWindow* _window)
{
	for (int i = 0; i < 3; i++)
	{
		sfRenderWindow_drawSprite(_window, keys[i].keySprite, NULL);
	}
}
