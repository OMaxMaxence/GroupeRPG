#include "key.h"

sfSprite* key;
sfTexture* key_texture;
sfFloatRect rectKey;
sfIntRect iRectKey = { 0,0,32,32 };
sfVector2f keyPos = { 200.0f, 200.0f };


void initKey()
{

	nb_key = 0;
	key = sfSprite_create();
	key_texture = sfTexture_createFromFile(TEXTURE_PATH"tilesetKEY.png", NULL);
	sfSprite_setTexture(key, key_texture, sfTrue);

	sfSprite_setTextureRect(key, iRectKey);
	sfSprite_setScale(key, vector2f(0.5f, 0.5f));
	iRectKey.left = 64;
	iRectKey.top = 32;

	sfSprite_setPosition(key, keyPos);
}

void updateKey()
{
	sfSprite_setTextureRect(key, iRectKey);
	sfSprite_setPosition(key, vector2f(keyPos.x - 115.0f, keyPos.y - 85.0f));
}


void displayKey(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, key, NULL);
}
