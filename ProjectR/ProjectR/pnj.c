#include "pnj.h"
#include "player.h"
#include "BlockText.h"
#define TEXTURE_PATH "../Ressources/Textures/" 

// D�claration et initialisation des variables utilis�es
sfTexture* spritesheetpnj; 
sfSprite* pnj;
sfIntRect iRectpnj = {0,0,32,32};
float animTimepnj = 0.0f;
float affichageText = 0.0f;
int textAfficher = 0;
sfVector2f pnjPos = { 40.0f, 250.0f };

//Fonction d'initialisation du pnj

void initPnj()
{
	//Application de la texture et de sa position 
	spritesheetpnj = sfTexture_createFromFile(TEXTURE_PATH"npc.png", NULL);
	pnj = sfSprite_create();
	sfSprite_setTexture(pnj, spritesheetpnj, sfTrue);
	sfSprite_setScale(pnj, vector2f(PNJ_SCALE, PNJ_SCALE));
	sfSprite_setOrigin(pnj, vector2f(16.0f, 16.0f));

	sfSprite_setTextureRect(pnj, iRectpnj);

	animTimepnj = 0.0f;
	framepnjX = 0;
	framepnjY = 0;

	sfSprite_setPosition(pnj, pnjPos); 

}

//Fonction de mise � jour du pnj
void updatePnj()
{
	//Gestion de l'animation du sprite
	animTimepnj += getDeltaTime();
	affichageText += getDeltaTime();

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
	if (textAfficher == 0 && sfKeyboard_isKeyPressed(sfKeySpace) && distanceToPlayer < 32 && affichageText >= 1)
	{
		printf("yo\n");
		textAfficher = 1;
		printf("%d\n", textAfficher);
		affichageText = 0;
		
	}
	if (textAfficher == 1 && sfKeyboard_isKeyPressed(sfKeySpace) && distanceToPlayer < 32 && affichageText >= 1)
	{
		printf("yolo\n");
		textAfficher = 0;
		printf("%d\n", textAfficher);
		affichageText = 0;
	}
	
}

//Fonction d'affichage du pnj
void displayPnj(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, pnj, NULL); 

	if (textAfficher == 1)
	{
		displayBlockText(_window);
	}
}
