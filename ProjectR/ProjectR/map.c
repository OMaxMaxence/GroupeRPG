//Liaison des fichiers
#include "tools.h"
#include "map.h"
#include "player.h"

#pragma warning (disable: 4244)

//Déclaration et initialisation des variables nécessaires
sfSprite* tileSpriteMap;
sfTexture* tileTextureMap;
sfVector2f tilePos = { 0.0f, 0.0f };
sfSprite* tileSpriteCoffre;
sfTexture* tileTextureCoffre;
sfVector2i mousePos;
int bloc = 0;
sfVector2i blocpos = { 0.0f, 0.0f };
float delai;
sfVector2f worldPos;
FILE* fichier;

//Génération de la taille de la map
char tileMap[MAP_HEIGHT][MAP_LENGTH]; /* = {
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 4},
	{ 0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0 },
	{ 0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0 },
	{ 0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0 },
	{ 0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0 },
	{ 0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0,0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0,0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0 },
	{ 0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0,0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0,0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0 },
	{ 4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 },
	{ 4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4 },
	{ 0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0 },
	{ 0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0 },
	{ 0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0 },
	{ 0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0 },
	{ 0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0,0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0,0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0 },
	{ 0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0,0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0,0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0 },
	{ 4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 },
	{ 4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4 },
	{ 0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,3,0,0,4,4,0,0 },
	{ 0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0,0,0,3,0,0 },
	{ 0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,0,0,3,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,4,7,4,2,1,0,0,0,0,0,0 },
	{ 0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,2,3,4,3,2,1,0,0,0,0,0,0 },
	{ 0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0,0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0,0,1,1,1,0,0,0,1,1,2,2,2,1,1,0,0,4,4,0,0 },
	{ 0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0,0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0,0,1,1,1,0,3,0,0,1,1,1,1,1,3,0,0,4,4,0,0 },
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
	{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
	{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
	{ 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};*/


//Fonction d'initialisation de la map
void initMap()
{
	//Application du tileset 
	tileTextureMap = sfTexture_createFromFile(TEXTURE_PATH"tileset1.png", NULL);
	tileSpriteMap = sfSprite_create();
	sfSprite_setTexture(tileSpriteMap, tileTextureMap, sfTrue);
	tileTextureCoffre = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
	tileSpriteCoffre = sfSprite_create();
	sfSprite_setTexture(tileSpriteCoffre, tileTextureCoffre, sfTrue); 

	//Ouverture de la map via le fichier de sauvegarde
	/*if (save = 1) 
	{*/
		fichier = fopen("savemap1.bin", "rb");
		fread(tileMap, sizeof(char), 7500, fichier);
		fclose(fichier);
	/* }
	else if (save = 2)
	{
		fichier = fopen("savemap2.bin", "rb");
		fread(tileMap, sizeof(char), 7500, fichier);
		fclose(fichier);
	}*/
	
}


//Fonction de mise à jour de la map du mode éditeur
void updateMap(sfRenderWindow* _window, float _t, sfView* _view)
{
	//Récupération de la position de la souris avec association au bloc à placer
	mousePos = sfMouse_getPosition(_window);
	worldPos = sfRenderWindow_mapPixelToCoords(_window, mousePos, editView);  
	blocpos.x = worldPos.x / 32;
	blocpos.y = worldPos.y / 32;
	delai += getDeltaTime();

	//Bouton pour changer les blocs à placer dans l'éditeur
	if (sfKeyboard_isKeyPressed(sfKeyUp) && delai > 0.3f)
	{
		delai = 0.0f;
		bloc = bloc + 1;
	}
	else if (sfKeyboard_isKeyPressed(sfKeyDown) && delai > 0.3f)
	{
		delai = 0.0f;
		bloc = bloc - 1;
	}
	if (bloc > 7)
	{
		bloc = 0;
	}
	else if (bloc < 0)
	{
		bloc = 7;
	} 
	//Application du bloc sélectionné sur la map en mode éditeur
	else if (sfMouse_isButtonPressed(sfMouseLeft))
	{
		if (worldPos.x < 3200 && worldPos.x > 0 && worldPos.y < 2400 && worldPos.y > 0)
		{
			tileMap[blocpos.y][blocpos.x] = bloc;  
		}
	}
	//Bouton de sauvegarde de la map dans un fichier de sauvegarde
	if (sfKeyboard_isKeyPressed(sfKeyM)) 
	{ 
		fichier = fopen("savemap1.bin", "wt"); 
		fwrite(tileMap, sizeof(char), MAP_HEIGHT*MAP_LENGTH, fichier); 
		fclose(fichier); 
	}

}
//Fonction de mise à jour de la map du mode jouer
void updateGameMap(sfRenderWindow* _window, float _t, sfView* _view)
{
}

//Fonction d'affichage de la map du mode éditeur
void displayMap(sfRenderWindow* _window, float _t)
{
	//Détection du bloc placé sur la map et affichage
	if (editeur = sfTrue)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			for (int x = 0; x < MAP_LENGTH; x++)
			{
				tilePos.x = x * 32;
				tilePos.y = y * 32;

				sfSprite_setPosition(tileSpriteMap, tilePos);
				sfSprite_setPosition(tileSpriteCoffre, tilePos);
				switch (tileMap[y][x])
				{
				case 0:
					sfSprite_setTextureRect(tileSpriteMap, T_TERRE);
					break;
				case 1:
					sfSprite_setTextureRect(tileSpriteMap, T_BOIS);
					break;
				case 2:
					sfSprite_setTextureRect(tileSpriteMap, T_EAU);
					break;
				case 3:
					sfSprite_setTextureRect(tileSpriteMap, T_ARBRE);
					break;
				case 4:
					sfSprite_setTextureRect(tileSpriteMap, T_PIERRE);
					break;
				case 5:
					sfSprite_setTextureRect(tileSpriteMap, T_COFFRE);
					break;
				case 6:
					sfSprite_setTextureRect(tileSpriteMap, T_DRAPEAU);
					break;
				case 7:
					sfSprite_setTextureRect(tileSpriteMap, T_PNJ); 
					break;
					/*case 6:
						if (_t >= 0 && _t < 1) sfSprite_setTextureRect(tileSpriteCoffre, T_FERMER);
						else if (_t >= 1 && _t < 2) sfSprite_setTextureRect(tileSpriteCoffre, T_QUART);
						else if (_t >= 2 && _t < 3)sfSprite_setTextureRect(tileSpriteCoffre, T_DEMI);
						else if (_t >= 3 && _t < 4)sfSprite_setTextureRect(tileSpriteCoffre, T_OUVERT);
						break;*/
				}
				//if (tileMap[y][x] == 5) sfRenderWindow_drawSprite(_window, tileSpriteCoffre, NULL);

				/*else*/ sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);

			}
		}

		//Affichage du bloc sélectionné à côté du curseur dans le mode éditeur
		switch (bloc)
		{ 
		case 0:
			tilePos.x = worldPos.x; 
			tilePos.y = worldPos.y; 
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_TERRE);  
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
		case 1:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_BOIS);  
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 2:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_EAU);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 3:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_ARBRE);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 4:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_PIERRE);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 5:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_COFFRE);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
		case 6:
			tilePos.x = worldPos.x; 
			tilePos.y = worldPos.y; 
			sfSprite_setPosition(tileSpriteMap, tilePos); 
			sfSprite_setTextureRect(tileSpriteMap, T_DRAPEAU);  
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
		case 7:
			tilePos.x = worldPos.x; 
			tilePos.y = worldPos.y; 
			sfSprite_setPosition(tileSpriteMap, tilePos); 
			sfSprite_setTextureRect(tileSpriteMap, T_PNJ); 
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
	}
	}
}

//Fonction d'affichage de la map du mode jouer
void displayGameMap(sfRenderWindow* _window, float _t)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_LENGTH; x++)
		{
			tilePos.x = x * 32;
			tilePos.y = y * 32;

			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setPosition(tileSpriteCoffre, tilePos);
			switch (tileMap[y][x])
			{
			case 0:
				sfSprite_setTextureRect(tileSpriteMap, T_TERRE);
				break;
			case 1:
				sfSprite_setTextureRect(tileSpriteMap, T_BOIS);
				break;
			case 2:
				sfSprite_setTextureRect(tileSpriteMap, T_EAU);
				break;
			case 3:
				sfSprite_setTextureRect(tileSpriteMap, T_ARBRE);
				break;
			case 4:
				sfSprite_setTextureRect(tileSpriteMap, T_PIERRE); 
				break;
			case 5:
				sfSprite_setTextureRect(tileSpriteMap, T_COFFRE); 
				break; 
			case 6:
				sfSprite_setTextureRect(tileSpriteMap, T_DRAPEAU); 
				break;
				/*case 6:
					if (_t >= 0 && _t < 1) sfSprite_setTextureRect(tileSpriteCoffre, T_FERMER);
					else if (_t >= 1 && _t < 2) sfSprite_setTextureRect(tileSpriteCoffre, T_QUART);
					else if (_t >= 2 && _t < 3)sfSprite_setTextureRect(tileSpriteCoffre, T_DEMI);
					else if (_t >= 3 && _t < 4)sfSprite_setTextureRect(tileSpriteCoffre, T_OUVERT);
					break;*/
			}
			//if (tileMap[y][x] == 5) sfRenderWindow_drawSprite(_window, tileSpriteCoffre, NULL);
			 
			/*else*/ sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 

		}
	}
}

//Génération des collisions entre certains bloc de la map et le personnage
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse)
{

	if (_direction == HAUT)
	{
		sfVector2i nextPosInTab = { _sprite.left / 32, (_sprite.top - _vitesse.y * getDeltaTime()) / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left + _sprite.width) / 32, (_sprite.top - _vitesse.y * getDeltaTime()) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] >= 3 && tileMap[nextPosInTab.y][nextPosInTab.x] <= 6 ||
			tileMap[nextPosInTab2.y][nextPosInTab2.x] >= 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] <= 6)
		{
			return sfTrue;
		}
	}

	else if (_direction == BAS)
	{
		sfVector2i nextPosInTab = { _sprite.left / 32, (_sprite.top + _sprite.height + _vitesse.y * getDeltaTime()) / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left + _sprite.width) / 32, (_sprite.top + _sprite.height + _vitesse.y * getDeltaTime()) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] >= 3 && tileMap[nextPosInTab.y][nextPosInTab.x] <= 6 ||
			tileMap[nextPosInTab2.y][nextPosInTab2.x] >= 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] <= 6)
		{
			return sfTrue;
		}
	}

	else if (_direction == GAUCHE)
	{
		sfVector2i nextPosInTab = { (_sprite.left - _vitesse.x * getDeltaTime()) / 32, (_sprite.top) / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left - _vitesse.x * getDeltaTime()) / 32, (_sprite.top + _sprite.height) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] >= 3 && tileMap[nextPosInTab.y][nextPosInTab.x] <= 6 ||
			tileMap[nextPosInTab2.y][nextPosInTab2.x] >= 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] <= 6)
		{
			return sfTrue;
		}
	}

	else if (_direction == DROITE)
	{
		sfVector2i nextPosInTab = { (_sprite.left + _sprite.width + _vitesse.x * getDeltaTime()) / 32, _sprite.top / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left + _sprite.width + _vitesse.x * getDeltaTime()) / 32, (_sprite.top + _sprite.height) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] >= 3 && tileMap[nextPosInTab.y][nextPosInTab.x] <= 6 ||
			tileMap[nextPosInTab2.y][nextPosInTab2.x] >= 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] <= 6)
		{
			return sfTrue;
		}
	}
	return sfFalse;
}