#include "pnj.h"
#define TEXTURE_PATH "../Ressources/Textures/"

sfTexture* spritesheetpnj;
sfSprite* pnj;
sfIntRect iRectpnj = {0,0,32,32};
float animTimepnj = 0.0f;

sfVector2f pnjPos = { 40.0f, 75.0f };


void initPnj()
{
	spritesheetpnj = sfTexture_createFromFile(TEXTURE_PATH"npc.png", NULL);
	pnj = sfSprite_create();
	sfSprite_setTexture(pnj, spritesheetpnj, sfTrue);
	sfSprite_setScale(pnj, vector2f(PNJ_SCALE, PNJ_SCALE));
	sfSprite_setOrigin(pnj, vector2f(16.0f, 16.0f));

	sfSprite_setTextureRect(pnj, iRectpnj);

	animTimepnj = 0.0f;
	framepnjX = 0;
	framepnjY = 0;
	sfVector2f pnjpos = vector2f(40.0f, 75.0f);

	sfSprite_setPosition(pnj, pnjpos); 

}

void updatePnj()
{
	animTimepnj += getDeltaTime();
	if (animTimepnj >= 1)
	{
		framepnjX++;
		if (framepnjX > 9) framepnjX = 0;

		iRectpnj.left = framepnjX * iRectpnj.width;
		sfSprite_setTextureRect(pnj, iRectpnj);
		animTimepnj = 0;
	}

	//sfSprite_setPosition(pnj, pnjPos);
	float distanceToPlayer = distanceBetweenTwoPoints(playerPos, pnjPos);
	
}

void displayPnj(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, pnj, NULL); 
}
