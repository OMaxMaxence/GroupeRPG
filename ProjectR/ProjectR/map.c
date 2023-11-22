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
	initKey();
	initChest();
	initPnj();
	initPlayer();
	initPorte();

	int nb_initChests = 0;

	//Application du tileset 
	tileTextureMap = sfTexture_createFromFile(TEXTURE_PATH"tileset1.png", NULL);
	tileSpriteMap = sfSprite_create();
	sfSprite_setTexture(tileSpriteMap, tileTextureMap, sfTrue);
	tileTextureCoffre = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
	tileSpriteCoffre = sfSprite_create();
	sfSprite_setTexture(tileSpriteCoffre, tileTextureCoffre, sfTrue); 

	//Ouverture de la map via le fichier de sauvegarde
	if (choixSave == MAINSAVE) 
	{
		fichier = fopen("savemap.bin", "r");
		fread(tileMap, sizeof(char), MAP_HEIGHT * MAP_LENGTH, fichier);
		fclose(fichier);
	 }
	else
	{
		fichier = fopen("savemap2.bin", "r");
		fread(tileMap, sizeof(char), MAP_HEIGHT * MAP_LENGTH, fichier);
		fclose(fichier);
	}

	//Affichage de la map
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_LENGTH; x++)
		{
			tilePos.x = x * 32;
			tilePos.y = y * 32;

			//Parcours la map pour detecter le nombre de coffre, porte, pnj, player
			switch (tileMap[y][x])
			{
			case 6:
				chests[nb_initChests].chestPos.x = x * 32.0f + 16.0f;
				chests[nb_initChests].chestPos.y = y * 32.0f + 16.0f;
				sfSprite_setPosition(chests[nb_initChests].chestSprite, chests[nb_initChests].chestPos);
				nb_initChests++;
				break;
			case 7:
				portes.portePos.x = x * 32.0f + 16.0f;
				portes.portePos.y = y * 32.0f + 16.0f;
				sfSprite_setPosition(portes.porteSprite, portes.portePos);
				break;
			case 8:
				pnjPos.x = x * 32.0f + 16.0f;
				pnjPos.y = y * 32.0f + 16.0f;
				sfSprite_setPosition(pnj, pnjPos);
				break;
			case 9:
				playerPos.x = x * 32.0f + 16.0f;
				playerPos.y = y * 32.0f + 16.0f;
				sfSprite_setPosition(player, playerPos);
				break;
			}
		}
	}
}


//Fonction de mise à jour de la map du mode éditeur
void updateMap(sfRenderWindow* _window, sfView* _view)
{
	//Récupération de la position de la souris avec association au bloc à placer
	mousePos = sfMouse_getPosition(_window);
	worldPos = sfRenderWindow_mapPixelToCoords(_window, mousePos, editView);  
	blocpos.x = worldPos.x / 32;
	blocpos.y = worldPos.y / 32;
	delai_menu += getDeltaTime();
	delai += getDeltaTime();

	//Bouton pour changer les blocs à placer dans l'éditeur
	if (sfKeyboard_isKeyPressed(sfKeyRight) && delai > 0.3f)
	{
		delai = 0.0f;
		bloc = bloc + 1;
	}
	else if (sfKeyboard_isKeyPressed(sfKeyLeft) && delai > 0.3f)
	{
		delai = 0.0f;
		bloc = bloc - 1;
	}
	//Rotation infini du choix des blocs
	if (bloc > 12)
	{
		bloc = 0;
	}
	else if (bloc < 0)
	{
		bloc = 12;
	} 
	//Application du bloc sélectionné sur la map en mode éditeur
	else if (sfMouse_isButtonPressed(sfMouseLeft) && delai_menu > 1.0f)
	{
		if (worldPos.x < 3200 && worldPos.x > 0 && worldPos.y < 2400 && worldPos.y > 0)
		{
			tileMap[blocpos.y][blocpos.x] = bloc;  
		}
	}
	//Bouton de sauvegarde de la map dans un fichier de sauvegarde
	if (sfKeyboard_isKeyPressed(sfKeyM) && delai > 0.5f)
	{ 
		delai = 0.0f;
		fichier = fopen("savemap2.bin", "w"); 
		fwrite(tileMap, sizeof(char), MAP_HEIGHT*MAP_LENGTH, fichier); 
		fclose(fichier); 
	}

}
//Fonction de mise à jour de la map du mode jouer
void updateGameMap(sfRenderWindow* _window, sfView* _view)
{
	updatePorte();
	updateChest();
	updatePnj();
	updatePlayer();
	updateKey();
}

//Fonction d'affichage de la map du mode éditeur
void displayMap(sfRenderWindow* _window)
{
	//Detection du bloc placé sur la map et affichage
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
					sfSprite_setTextureRect(tileSpriteMap, T_HERBECLAIR);
					break;
				case 1:
					sfSprite_setTextureRect(tileSpriteMap, T_TERRE);
					break;
				case 2:
					sfSprite_setTextureRect(tileSpriteMap, T_BOIS);
					break;
				case 3:
					sfSprite_setTextureRect(tileSpriteMap, T_EAUCLAIR);
					break;
				case 4:
					sfSprite_setTextureRect(tileSpriteMap, T_ARBRECLAIR);
					break;
				case 5:
					sfSprite_setTextureRect(tileSpriteMap, T_PIERRE);
					break;
				case 6:
					sfSprite_setTextureRect(tileSpriteMap, T_COFFRE);
					break;
				case 7:
					sfSprite_setTextureRect(tileSpriteMap, T_PORTE);
					break;
				case 8:
					sfSprite_setTextureRect(tileSpriteMap, T_PNJ);
					break;
				case 9:
					sfSprite_setTextureRect(tileSpriteMap, T_DRAPEAU);
					break;
				case 10:
					sfSprite_setTextureRect(tileSpriteMap, T_HERBEFONCE);
					break;
				case 11:
					sfSprite_setTextureRect(tileSpriteMap, T_ARBREFONCE);
					break;
				case 12:
					sfSprite_setTextureRect(tileSpriteMap, T_EAUFONCE);
					break;
				}
				 sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			}
		}

		//Affichage du bloc sélectionné à côté du curseur dans le mode éditeur
		switch (bloc)
		{ 
		case 0:
			tilePos.x = worldPos.x; 
			tilePos.y = worldPos.y; 
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_HERBECLAIR);  
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
		case 1:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_TERRE);  
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 2:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_BOIS);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 3:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_EAUCLAIR);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 4:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_ARBRECLAIR);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 5:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_PIERRE);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
		case 6:
			tilePos.x = worldPos.x; 
			tilePos.y = worldPos.y; 
			sfSprite_setPosition(tileSpriteMap, tilePos); 
			sfSprite_setTextureRect(tileSpriteMap, T_COFFRE);  
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
		case 7:
			tilePos.x = worldPos.x; 
			tilePos.y = worldPos.y; 
			sfSprite_setPosition(tileSpriteMap, tilePos); 
			sfSprite_setTextureRect(tileSpriteMap, T_PORTE);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
			break;
		case 8:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_PNJ);
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 9:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_DRAPEAU); 
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 10:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_HERBEFONCE); 
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 11:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_ARBREFONCE); 
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
		case 12:
			tilePos.x = worldPos.x;
			tilePos.y = worldPos.y;
			sfSprite_setPosition(tileSpriteMap, tilePos);
			sfSprite_setTextureRect(tileSpriteMap, T_EAUFONCE); 
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);
			break;
	}
	}
}

//Fonction d'affichage de la map du mode jouer
void displayGameMap(sfRenderWindow* _window)
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
				sfSprite_setTextureRect(tileSpriteMap, T_HERBECLAIR);  
				break;
			case 1:
				sfSprite_setTextureRect(tileSpriteMap, T_TERRE);
				break;
			case 2:
				sfSprite_setTextureRect(tileSpriteMap, T_BOIS);
				break;
			case 3:
				sfSprite_setTextureRect(tileSpriteMap, T_EAUCLAIR);
				break;
			case 4:
				sfSprite_setTextureRect(tileSpriteMap, T_ARBRECLAIR);
				break;
			case 5:
				sfSprite_setTextureRect(tileSpriteMap, T_PIERRE);
				break;
			case 6:
				sfSprite_setTextureRect(tileSpriteMap, T_COFFRE);
				break;
			case 7:
				sfSprite_setTextureRect(tileSpriteMap, T_HERBECLAIR); // FOND PORTE
				break;
			case 8:
				sfSprite_setTextureRect(tileSpriteMap, T_HERBECLAIR); // FOND PNJ
				break;
			case 9:
				sfSprite_setTextureRect(tileSpriteMap, T_HERBECLAIR); // FOND DRAPEAU
				break;
			case 10:
				sfSprite_setTextureRect(tileSpriteMap, T_HERBEFONCE);
				break;
			case 11:
				sfSprite_setTextureRect(tileSpriteMap, T_ARBREFONCE); 
				break;
			case 12:
				sfSprite_setTextureRect(tileSpriteMap, T_EAUFONCE); 
				break;
				
			}			 
			sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL); 
		}
	}


	displayChest(_window);
	displayPorte(_window);
	displayPnj(_window);
	displayPlayer(_window);
	displayKey(_window);
}

//Génération des collisions entre certains bloc de la map et le personnage
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse)
{
	
	if (_direction == HAUT)
	{
		//Collision ralentissement
		sfVector2i nextPosInTab = { _sprite.left / 32, (_sprite.top - _vitesse.y * getDeltaTime()) / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left + _sprite.width) / 32, (_sprite.top - _vitesse.y * getDeltaTime()) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] == 3 || tileMap[nextPosInTab2.y][nextPosInTab2.x] == 3) // Player in water
		{
			playerSpeed.x = PLAYER_SPEED / 2;
			playerSpeed.y = PLAYER_SPEED / 2;
		}
		else
		{
			playerSpeed.x = PLAYER_SPEED;
			playerSpeed.y = PLAYER_SPEED;
		}
		//Franchissement de la porte
		if ((tileMap[nextPosInTab.y][nextPosInTab.x] == 7 || tileMap[nextPosInTab2.y][nextPosInTab2.x] == 7) && portes.porteRect.left >= 96) // Player opens the door
		{
			return sfFalse;
		}
		//Collision type mur 
		if (tileMap[nextPosInTab.y][nextPosInTab.x] > 3 && tileMap[nextPosInTab.y][nextPosInTab.x] < 9 || tileMap[nextPosInTab.y][nextPosInTab.x] > 10 && tileMap[nextPosInTab.y][nextPosInTab.x] < 13 ||
			tileMap[nextPosInTab2.y][nextPosInTab2.x] > 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 9 || tileMap[nextPosInTab2.y][nextPosInTab2.x] > 10 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 13) // Choix des blocs à collision 
		{
			return sfTrue;
		}
	}

	else if (_direction == BAS)
	{
		//Collision ralentissement
		sfVector2i nextPosInTab = { _sprite.left / 32, (_sprite.top + _sprite.height + _vitesse.y * getDeltaTime()) / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left + _sprite.width) / 32, (_sprite.top + _sprite.height + _vitesse.y * getDeltaTime()) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] == 3 || tileMap[nextPosInTab2.y][nextPosInTab2.x] == 3) // Player in water
		{
			playerSpeed.x = PLAYER_SPEED / 2;
			playerSpeed.y = PLAYER_SPEED / 2;
		}
		else
		{
			playerSpeed.x = PLAYER_SPEED;
			playerSpeed.y = PLAYER_SPEED;
		}
		//Franchissement de la porte
		if ((tileMap[nextPosInTab.y][nextPosInTab.x] == 7 || tileMap[nextPosInTab2.y][nextPosInTab2.x] == 7) && portes.porteRect.left >= 96) // Player opens the door
		{
			return sfFalse;
		}
		//Collision type mur
		if (tileMap[nextPosInTab.y][nextPosInTab.x] > 3 && tileMap[nextPosInTab.y][nextPosInTab.x] < 9 || tileMap[nextPosInTab.y][nextPosInTab.x] > 10 && tileMap[nextPosInTab.y][nextPosInTab.x] < 13 ||
			tileMap[nextPosInTab2.y][nextPosInTab2.x] > 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 9 || tileMap[nextPosInTab2.y][nextPosInTab2.x] > 10 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 13) // Choix des blocs à collision 
		{
			return sfTrue;
		}
	}

	else if (_direction == GAUCHE)
	{
		//Collision ralentissement
		sfVector2i nextPosInTab = { (_sprite.left - _vitesse.x * getDeltaTime()) / 32, (_sprite.top) / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left - _vitesse.x * getDeltaTime()) / 32, (_sprite.top + _sprite.height) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] == 3 || tileMap[nextPosInTab2.y][nextPosInTab2.x] == 3) // Player in water
		{
			playerSpeed.x = PLAYER_SPEED / 2;
			playerSpeed.y = PLAYER_SPEED / 2;
		}
		else
		{
			playerSpeed.x = PLAYER_SPEED;
			playerSpeed.y = PLAYER_SPEED;
		}
		//Collision type mur
		if (tileMap[nextPosInTab.y][nextPosInTab.x] > 3 && tileMap[nextPosInTab.y][nextPosInTab.x] < 9 || tileMap[nextPosInTab.y][nextPosInTab.x] > 10 && tileMap[nextPosInTab.y][nextPosInTab.x] < 13 ||
			tileMap[nextPosInTab2.y][nextPosInTab2.x] > 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 9 || tileMap[nextPosInTab2.y][nextPosInTab2.x] > 10 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 13) // Choix des blocs à collision
		{
			return sfTrue;
		}
	}

	else if (_direction == DROITE)
	{
		//Collision ralentissement
		sfVector2i nextPosInTab = { (_sprite.left + _sprite.width + _vitesse.x * getDeltaTime()) / 32, _sprite.top / 32 };
		sfVector2i nextPosInTab2 = { (_sprite.left + _sprite.width + _vitesse.x * getDeltaTime()) / 32, (_sprite.top + _sprite.height) / 32 };
		if (tileMap[nextPosInTab.y][nextPosInTab.x] == 3 || tileMap[nextPosInTab2.y][nextPosInTab2.x] == 3) // Player in water
		{
			playerSpeed.x = PLAYER_SPEED / 2;
			playerSpeed.y = PLAYER_SPEED / 2;
		}
		else
		{
			playerSpeed.x = PLAYER_SPEED;
			playerSpeed.y = PLAYER_SPEED;
		}
		//Collision type mur
		if (tileMap[nextPosInTab.y][nextPosInTab.x] > 3 && tileMap[nextPosInTab.y][nextPosInTab.x] < 9 || tileMap[nextPosInTab.y][nextPosInTab.x] > 10 && tileMap[nextPosInTab.y][nextPosInTab.x] < 13 || 
			tileMap[nextPosInTab2.y][nextPosInTab2.x] >3 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 9 || tileMap[nextPosInTab2.y][nextPosInTab2.x] > 10 && tileMap[nextPosInTab2.y][nextPosInTab2.x] < 13) // Choix des blocs à collision
		{
			return sfTrue;
		}
	}
	return sfFalse;
}