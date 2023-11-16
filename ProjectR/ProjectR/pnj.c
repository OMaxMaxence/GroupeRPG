#include "pnj.h"
#define TEXTURE_PATH "../Ressources/Textures/"

sfTexture* spritesheetpnj;
sfSprite* pnj;
sfIntRect iRectpnj = {0,0,31,32};
float animTimepnj = 0.0f;

sfVector2f pnjPos = { 164.0f, 164.0f };
void initPnj()
{
	spritesheetpnj = sfTexture_createFromFile(TEXTURE_PATH"npc.png", NULL);
	pnj = sfSprite_create();
	sfSprite_setTexture(pnj, spritesheetpnj, sfTrue);
	sfSprite_setScale(pnj, vector2f(PNJ_SCALE, PNJ_SCALE));
	sfSprite_setOrigin(pnj, vector2f(8.5f, 11.5f));

	sfSprite_setTextureRect(pnj, iRectpnj);

	animTimepnj = 0.0f;
	framepnjX = 0;
	framepnjY = 0;
	sfVector2f pnjpos = vector2f(40.0f, 75.0f);

	sfSprite_setPosition(pnj, pnjpos); 

}

void updatePnj()
{
	// Animation non fonctionnel
	/*
	if (animTimepnj > 0.3f)
	{
		for (int i = 0; i < 11; i++)
		{
			iRectpnj.left = 0 + 18 * i;
			sfSprite_setTextureRect(pnj, iRectpnj);
		}
		animTimepnj = 0.0f;
	}*/
	
}

void displayPnj(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, pnj, NULL); 
}
