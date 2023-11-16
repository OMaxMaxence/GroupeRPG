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
#define T_DRAPEAU (sfIntRect){224,0,32,32} 
#define T_FERMER (sfIntRect){0,0,32,32}
#define T_QUART (sfIntRect){32,0,32,32}
#define T_DEMI (sfIntRect){64,0,32,32}
#define T_OUVERT (sfIntRect){ 96,0,32,32}

#pragma warning (disable: 4244)

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



void initMap()
{
	tileTextureMap = sfTexture_createFromFile(TEXTURE_PATH"tileset1.png", NULL);
	tileSpriteMap = sfSprite_create();
	sfSprite_setTexture(tileSpriteMap, tileTextureMap, sfTrue);
	tileTextureCoffre = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
	tileSpriteCoffre = sfSprite_create();
	sfSprite_setTexture(tileSpriteCoffre, tileTextureCoffre, sfTrue); 
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



void updateMap(sfRenderWindow* _window, float _t, sfView* _view)
{
	mousePos = sfMouse_getPosition(_window);
	worldPos = sfRenderWindow_mapPixelToCoords(_window, mousePos, view); 
	blocpos.x = worldPos.x / 32;
	blocpos.y = worldPos.y / 32;
	delai += getDeltaTime();
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
	if (bloc > 5)
	{
		bloc = 0;
	}
	else if (bloc < 0)
	{
		bloc = 5;
	} 
	else if (sfMouse_isButtonPressed(sfMouseLeft))
	{
		if (worldPos.x < 3200 && worldPos.x > 0 && worldPos.y < 2400 && worldPos.y > 0)
		{
			tileMap[blocpos.y][blocpos.x] = bloc;  
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyM)) 
	{ 
		fichier = fopen("savemap1.bin", "wt"); 
		fwrite(tileMap, sizeof(char), 7500, fichier); 
		fclose(fichier); 
	}

}



void displayMap(sfRenderWindow* _window, float _t)
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
			if (tileMap[y][x] == 6) sfRenderWindow_drawSprite(_window, tileSpriteCoffre, NULL);

			else sfRenderWindow_drawSprite(_window, tileSpriteMap, NULL);

		}
	}

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