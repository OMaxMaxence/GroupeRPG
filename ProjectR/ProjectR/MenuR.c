#include "MenuR.h"



sfSprite* SpriteBackgroundMenu;
sfTexture* TextureBackgroundMenu;
sfVector2f origin = { 400.0f, 300.0f };
sfVector2f pos = { 400.0f, 300.0f };
float angle = 0.0f;
sfSprite* SpritePlayMenu;
sfTexture* TexturePlayMenu;
sfVector2f originPlay = { 143.0f, 46.5f };
sfVector2f posPlay = { 400.0f, 300.0f };
sfVector2i mousePosMenu; 
sfFloatRect rectPlay;


void initMenu()
{

	SpriteBackgroundMenu = sfSprite_create();
	TextureBackgroundMenu = sfTexture_createFromFile("..\\Ressources\\Textures\\MenuBackgroundRPG.png", NULL);
	sfSprite_setTexture(SpriteBackgroundMenu, TextureBackgroundMenu, sfTrue);
	sfSprite_setOrigin(SpriteBackgroundMenu, origin);
	sfSprite_setPosition(SpriteBackgroundMenu, pos);
	sfSprite_setRotation(SpriteBackgroundMenu, angle);
	SpritePlayMenu = sfSprite_create();
	TexturePlayMenu = sfTexture_createFromFile("..\\Ressources\\Textures\\BlockPlay.png", NULL);
	sfSprite_setTexture(SpritePlayMenu, TexturePlayMenu, sfTrue);
	sfSprite_setOrigin(SpritePlayMenu, vector2f(sfSprite_getGlobalBounds(SpritePlayMenu).width / 2, sfSprite_getGlobalBounds(SpritePlayMenu).height / 2));
	sfSprite_setPosition(SpritePlayMenu, posPlay);
	rectPlay = sfSprite_getGlobalBounds(SpritePlayMenu);
	mousePosMenu = sfMouse_getPosition(window);
}

void updateMenu(sfRenderWindow* _window, sfView* _view)
{
	
	worldPos = sfRenderWindow_mapPixelToCoords(_window, mousePosMenu, _view);
	if (sfFloatRect_contains(&rectPlay, worldPos.x, worldPos.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			exit(EXIT_SUCCESS);
		}
	}
}

void displayMenu(sfRenderWindow* _window)
{
	sfSprite_setOrigin(SpriteBackgroundMenu, origin);

	sfSprite_setOrigin(SpritePlayMenu, vector2f(sfSprite_getGlobalBounds(SpritePlayMenu).width / 2, sfSprite_getGlobalBounds(SpritePlayMenu).height / 2));
	sfSprite_setPosition(SpriteBackgroundMenu, pos);
	sfSprite_setPosition(SpritePlayMenu, posPlay);
	sfSprite_setRotation(SpriteBackgroundMenu, angle);
	sfRenderWindow_drawSprite(_window, SpriteBackgroundMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpritePlayMenu, NULL);
}