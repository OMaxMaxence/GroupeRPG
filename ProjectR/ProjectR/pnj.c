#include "pnj.h"
#include "player.h"
#include "BlockText.h"

// Déclaration et initialisation des variables utilisées
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

//Fonction de mise à jour du pnj
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
	//Detection de la distance entre le player et le pnj
	float distanceToPlayer = distanceBetweenTwoPoints(playerPos, pnjPos);
	//Bouton interaction
	if (textAfficher == 0 && sfKeyboard_isKeyPressed(sfKeySpace) && distanceToPlayer < 40 && affichageText >= 0.3f)
	{
		textAfficher = 1;
		affichageText = 0;
		
	}
	if (textAfficher == 1 && sfKeyboard_isKeyPressed(sfKeySpace) && distanceToPlayer < 40 && affichageText >= 0.3f)
	{
		textAfficher = 0;
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
