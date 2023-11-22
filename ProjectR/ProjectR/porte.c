#include "porte.h"

//Fonction initialisation
void initPorte()
{
	portes.portePos.x = 150.0f; 
	portes.portePos.y = 32.0f;
	portes.porteRect.width = 32;
	portes.porteRect.height = 32;
	portes.porteRect.top = 0;
	portes.porteRect.left = 0;
	portes.porteCode = 0; 
	portes.porteSprite = sfSprite_create(); 
	portes.porteTexture = sfTexture_createFromFile(TEXTURE_PATH"porte.png", NULL);
	sfSprite_setTexture(portes.porteSprite, portes.porteTexture, sfTrue); 
	sfSprite_setTextureRect(portes.porteSprite, portes.porteRect); 
	sfSprite_setPosition(portes.porteSprite, portes.portePos); 
	sfSprite_setOrigin(portes.porteSprite, vector2f(16.0f, 16.0f)); 
}

//Fonction Mise à jour
float porteTimer = 0.0f; 
void updatePorte()
{
	porteTimer += getDeltaTime();
	//Detection de la distance entre le player et la porte
	float distToPlayerPorte = distanceBetweenTwoPoints(portes.portePos, playerPos);
	//Bouton interaction
		if (sfKeyboard_isKeyPressed(sfKeySpace) && distToPlayerPorte < 40.0f && nb_key >= 3) 
		{
			portes.openPorte = sfTrue;  
		}
		//Animation de la porte
		if (porteTimer > 1.0f && portes.openPorte == sfTrue && portes.porteRect.left < 96) 
		{
			portes.porteRect.left += 32; 
			sfSprite_setTextureRect(portes.porteSprite, portes.porteRect); 
			sfSprite_setPosition(portes.porteSprite, portes.portePos); 
			porteTimer = 0;  
		}
}

//Fonction affichage
void displayPorte(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, portes.porteSprite, NULL); 
}
