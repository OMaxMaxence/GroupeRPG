#include "tools.h"
#include "map.h"
#include "player.h"
#define TEXTURE_PATH "../Ressources/Textures/"
#define T_VIDE (sfIntRect){0,0,32,32}
#define T_BOIS (sfIntRect){32,0,32,32}
#define T_TERRE (sfIntRect){64,0,32,32}
#define T_EAU (sfIntRect){ 96,0,32,32}
#define T_ARBRE (sfIntRect){128,0,32,32}
#define T_PIERRE (sfIntRect){160,0,32,32}
#define T_COFFRE (sfIntRect){192,0,32,32}
#define T_FERMER (sfIntRect){0,0,32,32}
#define T_QUART (sfIntRect){32,0,32,32}
#define T_DEMI (sfIntRect){64,0,32,32}
#define T_OUVERT (sfIntRect){ 96,0,32,32}

#pragma warning (disable: 4244)

sfSprite* tileSprite;
sfTexture* tileTexture;
sfVector2f tilePos = { 0,0 };
sfSprite* tileSprite2;
sfTexture* tileTexture2;
sfSprite* persnageSprite;
sfTexture* persnageTexture;
sfVector2i mousePos;
sfVector2i tilePosition;
int tile;
sfVector2i pixelPos;
sfVector2f worldPos;
FILE* fichier;

char tileMap[75][100]; /* = {
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

void initMap()
{
	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"tileset1.png", NULL);
	tileSprite = sfSprite_create();
	sfSprite_setTexture(tileSprite, tileTexture, sfTrue);
	tileTexture2 = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
	tileSprite2 = sfSprite_create();
	sfSprite_setTexture(tileSprite2, tileTexture2, sfTrue);
	tile = 0;
	/*if (save = 1)
	{
		fichier = fopen("savemap1.bin", "rb");
		fread(tileMap, sizeof(char), 7500, fichier);
	}
	else if (save = 2)
	{
		fichier = fopen("savemap2.bin", "rb");
		fread(tileMap, sizeof(char), 7500, fichier);
	}*/
	
}

void updateMap(sfRenderWindow* _window, float _t, sfView* _view)
{
	if (sfKeyboard_isKeyPressed(sfKeyM)) 
	{ 
		fichier = fopen("savemap1.bin", "wt"); 
		fwrite(tileMap, sizeof(char), 7500, fichier); 
		fclose(fichier); 
	}
}

void displayMap(sfRenderWindow* _window, float _t)
{
	for (int y = 0; y < 75; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			tilePos.x = x * 32;
			tilePos.y = y * 32;

			sfSprite_setPosition(tileSprite, tilePos);
			sfSprite_setPosition(tileSprite2, tilePos);
			switch (tileMap[y][x])
			{
			case 0:
				sfSprite_setTextureRect(tileSprite, T_TERRE); 
				break;
			case 1:
				sfSprite_setTextureRect(tileSprite, T_BOIS); 
				break;
			case 2:
				sfSprite_setTextureRect(tileSprite, T_EAU);
				break;
			case 3:
				sfSprite_setTextureRect(tileSprite, T_ARBRE);
				break;
			case 4:
				sfSprite_setTextureRect(tileSprite, T_PIERRE);
				break;
			case 5:
				sfSprite_setTextureRect(tileSprite, T_COFFRE);
				break;
			case 6:
				sfSprite_setTextureRect(tileSprite, T_PIERRE);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				sfSprite_setTextureRect(tileSprite, T_COFFRE);
				break;
			case 7:				
				if (_t >= 0 && _t < 1) sfSprite_setTextureRect(tileSprite2, T_FERMER);
				else if (_t >= 1 && _t < 2) sfSprite_setTextureRect(tileSprite2, T_QUART);
				else if (_t >= 2 && _t < 3)sfSprite_setTextureRect(tileSprite2, T_DEMI);
				else if (_t >= 3 && _t < 4)sfSprite_setTextureRect(tileSprite2, T_OUVERT);
				break;
			}
			if (tileMap[y][x] == 7) sfRenderWindow_drawSprite(_window, tileSprite2, NULL);

			else sfRenderWindow_drawSprite(_window, tileSprite, NULL);

		}
	}
}

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