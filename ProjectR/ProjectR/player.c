#include "player.h"

sfTexture* spritesheet;
sfSprite* player;
sfIntRect iRect = { 0,0,17,23 };
sfFloatRect frect;
float animTime = 0.0f;
sfBool isMoving;

sfVector2f playerPos = { 100.0f, 100.0f };
sfVector2f playerSpeed = { PLAYER_SPEED, PLAYER_SPEED };

sfSprite* spacebar;
sfTexture* spacebarTexture;
sfVector2f spacebarPos;
sfFloatRect spacebarFloatRect;
float spacebarAngleRotation = 0.0f;
float spacebarSpeedRotation = 40.0f;

void initPlayer()
{
	spritesheet = sfTexture_createFromFile(TEXTURE_PATH"link.png", NULL); 
	player = sfSprite_create();
	sfSprite_setTexture(player, spritesheet, sfTrue);
	sfSprite_setScale(player, vector2f(PLAYER_SCALE, PLAYER_SCALE));
	sfSprite_setOrigin(player, vector2f(8.5f, 11.5f));
	iRect.top = 0;
	iRect.left = 0;
	sfSprite_setTextureRect(player, iRect);

	animTime = 0.0f;
	frameX = 0;
	frameY = 0;
	isMoving = sfFalse;

	sfSprite_setPosition(player, playerPos);

	sfFloatRect frect = sfSprite_getGlobalBounds(player);

	spacebarTexture = sfTexture_createFromFile(TEXTURE_PATH"spacebar.png", NULL);
	spacebar = sfSprite_create();
	sfSprite_setTexture(spacebar, spacebarTexture, sfTrue);
	sfSprite_setScale(spacebar, vector2f(0.05f, 0.05f));
	spacebarFloatRect = sfSprite_getGlobalBounds(spacebar);
	sfSprite_setOrigin(spacebar, vector2f(250.0f, 250.0f));

}



void updatePlayer()
{
	frect = sfSprite_getGlobalBounds(player);
	isMoving = sfFalse;

	if (sfKeyboard_isKeyPressed(sfKeyD) && playerPos.x < MAP_LENGTH*32 - PLAYER_LENGTH/2)
	{
		frameY = DROITE;
		if (!collisionMapPlayer(frect, DROITE, playerSpeed))
		{
			playerPos.x += playerSpeed.x * getDeltaTime();
			isMoving = sfTrue;
			animTime += getDeltaTime();
		}
	}
	else if (sfKeyboard_isKeyPressed(sfKeyZ) && playerPos.y > PLAYER_HEIGHT/2)
	{
		frameY = HAUT;
		if (!collisionMapPlayer(frect, HAUT, playerSpeed))
		{
			playerPos.y -= playerSpeed.y * getDeltaTime();
			isMoving = sfTrue;
			animTime += getDeltaTime();
		}
	}
	else if (sfKeyboard_isKeyPressed(sfKeyQ) && playerPos.x > PLAYER_LENGTH/2)
	{
		frameY = GAUCHE;
		if (!collisionMapPlayer(frect, GAUCHE, playerSpeed))
		{
			playerPos.x -= playerSpeed.x * getDeltaTime();
			isMoving = sfTrue;
			animTime += getDeltaTime();
		}
	}
	else if (sfKeyboard_isKeyPressed(sfKeyS) && playerPos.y < MAP_HEIGHT*32 - PLAYER_HEIGHT/2)
	{
		frameY = BAS;
		if (!collisionMapPlayer(frect, BAS, playerSpeed))
		{
			playerPos.y += playerSpeed.y * getDeltaTime();
			isMoving = sfTrue;
			animTime += getDeltaTime();
		}

	}

	if (isMoving)
	{
		if (animTime > ANIM_SPEED)
		{
			frameX++;
			if (frameX > 8) frameX = 0;
			iRect.left = frameX * iRect.width;
			iRect.top = frameY * iRect.height;
			sfSprite_setTextureRect(player, iRect);
			animTime = 0.0f;
		}
	}
	else {
		frameX = 0;
		iRect.left = frameX * iRect.width;
		sfSprite_setTextureRect(player, iRect);
	}

	sfSprite_setPosition(player, playerPos);
	
	if (showSpacebar())
	{
		spacebarPos = vector2f(playerPos.x , playerPos.y + 21.0f);
		sfSprite_setPosition(spacebar, spacebarPos);
		//if (spacebarAngleRotation < 40.0f && spacebarAngleRotation >-50.0f)
		//{
		//	spacebarAngleRotation += spacebarSpeedRotation * getDeltaTime();
		//}
		if (spacebarAngleRotation > 30.0f)
		{
			spacebarSpeedRotation = -spacebarSpeedRotation;
			//spacebarAngleRotation -= spacebarSpeedRotation * getDeltaTime();
		}
		if (spacebarAngleRotation < -30.0f)
		{
			spacebarSpeedRotation = -spacebarSpeedRotation;
		}
		spacebarAngleRotation += spacebarSpeedRotation * getDeltaTime();
		sfSprite_setRotation(spacebar, spacebarAngleRotation);
		//sfSprite_rotate(spacebar, spacebarAngleRotation);

	}

}

void displayPlayer(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, player, NULL);

	if (showSpacebar())
	{
		sfRenderWindow_drawSprite(_window, spacebar, NULL);
	}
}

sfBool showSpacebar()
{
	for (int i = 0; i < 3; i++)
	{
		float distanceToChest = distanceBetweenTwoPoints(chests[i].chestPos, playerPos);
		if (distanceToChest < 40.0f) return sfTrue;
	}
	float distanceToPnj = distanceBetweenTwoPoints(pnjPos, playerPos);

	if (distanceToPnj < 40.0f) return sfTrue;

	float distanceToDoor = distanceBetweenTwoPoints(portes.portePos, playerPos);
	if (distanceToDoor < 40.0f) return sfTrue;

	return sfFalse;
}
