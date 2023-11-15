#include "player.h"

sfTexture* spritesheet;
sfSprite* player;
sfIntRect iRect = { 0,0,17,23 };
sfFloatRect frect;
float animTime = 0.0f;
sfBool isMoving;

sfVector2f playerPos = { 100.0f, 100.0f };
sfVector2f playerSpeed = { 150.0f, 150.0 };

void initPlayer()
{
	spritesheet = sfTexture_createFromFile("..\\Ressources\\Textures\\link.png", NULL);
	player = sfSprite_create();
	sfSprite_setTexture(player, spritesheet, sfTrue);
	sfSprite_setScale(player, vector2f(PLAYER_SCALE, PLAYER_SCALE));
	sfSprite_setOrigin(player, vector2f(8.5f, 11.5f));

	sfSprite_setTextureRect(player, iRect);

	animTime = 0.0f;
	frameX = 0;
	frameY;
	isMoving = sfFalse;

	sfVector2f playerpos = vector2f(0.0f, 0.0f);

	sfSprite_setPosition(player, playerpos);

	sfFloatRect frect = sfSprite_getGlobalBounds(player);

}



void updatePlayer()
{
	frect = sfSprite_getGlobalBounds(player);
	isMoving = sfFalse;

	if (sfKeyboard_isKeyPressed(sfKeyD))
	{
		frameY = 1; // DROITE
		// if !collision
		playerPos.y -= playerSpeed.y * getDeltaTime();
		isMoving = sfTrue;
		animTime += getDeltaTime();
	}
}

void displayPlayer(sfRenderWindow* _window)
{
}
