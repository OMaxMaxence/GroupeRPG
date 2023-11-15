#include "MenuR.h"



sfSprite* monSprite;
sfTexture* maTexture;
sfVector2f origin = { 400.0f, 300.0f };
sfVector2f pos = { 400.0f, 300.0f };
float angle = 0.0f;
sfRectangleShape* rectangle;
sfVector2f rectsize = { 300.0f, 70.0f };
sfVector2f rectOrigin = { 150.0f, 35.0f };
sfVector2f retanglePos = { 400.0f, 50.0f };


void initMenu()
{
	monSprite = sfSprite_create();
	maTexture = sfTexture_createFromFile("..\\Ressources\\Textures\\MenuBackgroundRPG.png", NULL);
	sfSprite_setTexture(monSprite, maTexture, sfTrue);
	sfSprite_setOrigin(monSprite, origin);
	sfSprite_setPosition(monSprite, pos);
	sfSprite_setRotation(monSprite, angle);
	rectangle = sfRectangleShape_create();
	sfRectangleShape_setSize(rectangle, rectsize);
	sfSprite_setOrigin(rectangle, rectOrigin);
	sfRectangleShape_setPosition(rectangle, retanglePos);
}

void updateMenu()
{
	
}

void displayMenu(sfRenderWindow* _window)
{
	sfSprite_setOrigin(monSprite, origin);
	sfSprite_setPosition(monSprite, pos);
	sfSprite_setRotation(monSprite, angle);
	sfRenderWindow_drawSprite(_window, monSprite, NULL);
	sfRenderWindow_drawRectangleShape(_window, rectangle, NULL);
}