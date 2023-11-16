#include "MenuR.h"



sfSprite* SpriteBackgroundMenu;
sfTexture* TextureBackgroundMenu;
sfVector2f origin = { 400.0f, 300.0f };
sfVector2f pos = { 400.0f, 300.0f };
float angle = 0.0f;
sfSprite* SpritePlayMenu;
sfTexture* TexturePlayMenu;
sfVector2f posPlay = { 100.0f, 450.0f };
sfVector2i mousePosMenu; 
sfFloatRect rectPlay;
sfSprite* SpriteEditMenu;
sfTexture* TextureEditMenu;
sfVector2f posEdit = { 400.0f, 450.0f };
sfVector2i mousePosMenu;
sfFloatRect rectEdit;
sfSprite* SpriteQuitterMenu;
sfTexture* TextureQuitterMenu;
sfVector2f posQuitter = { 700.0f, 450.0f };
sfVector2i mousePosMenu;
sfFloatRect rectQuitter;



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
	SpriteEditMenu = sfSprite_create();
	TextureEditMenu = sfTexture_createFromFile("..\\Ressources\\Textures\\BlockEditer.png", NULL);
	sfSprite_setTexture(SpriteEditMenu, TextureEditMenu, sfTrue);
	sfSprite_setOrigin(SpriteEditMenu, vector2f(sfSprite_getGlobalBounds(SpriteEditMenu).width / 2, sfSprite_getGlobalBounds(SpriteEditMenu).height / 2));
	sfSprite_setPosition(SpriteEditMenu, posEdit);
	SpriteQuitterMenu = sfSprite_create();
	TextureQuitterMenu = sfTexture_createFromFile("..\\Ressources\\Textures\\BlockQuitter.png", NULL);
	sfSprite_setTexture(SpriteQuitterMenu, TextureQuitterMenu, sfTrue);
	sfSprite_setOrigin(SpriteQuitterMenu, vector2f(sfSprite_getGlobalBounds(SpriteQuitterMenu).width / 2, sfSprite_getGlobalBounds(SpriteQuitterMenu).height / 2));
	sfSprite_setPosition(SpriteQuitterMenu, posQuitter);
	musicMenu = sfMusic_createFromFile("..\\Ressources\\Musics\\Musique-libre-de-droits_-Epic-Music-CELTIC-FANTASY-MUSIC-Dark-Ambience-Medieval-_No-Copyright_.ogg");
	sfMusic_play(musicMenu);
	musicEdit = sfMusic_createFromFile("..\\Ressources\\Musics\\Geometry-Dash-Practice-Mode-Song-1-Hour.ogg");
	musicJouer = sfMusic_createFromFile("..\\Ressources\\Musics\\Crazy-Frog-Axel-F-1-Hour.ogg");
}

void updateMenu(sfRenderWindow* _window, sfView* _view)
{
	
	mousePosMenu = sfMouse_getPosition(_window);
	rectPlay = sfSprite_getGlobalBounds(SpritePlayMenu);
	rectEdit = sfSprite_getGlobalBounds(SpriteEditMenu);
	rectQuitter = sfSprite_getGlobalBounds(SpriteQuitterMenu);
	printf("yo\n");
	//worldPos = sfRenderWindow_mapPixelToCoords(_window, mousePosMenu, _view);
	if (sfFloatRect_contains(&rectPlay, mousePosMenu.x, mousePosMenu.y))
	{
		printf("yolo\n");
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			sfMusic_stop(musicMenu);
			sfMusic_play(musicJouer);
			choixJoueurMenu = JOUER;
			printf("%d\n", choixJoueurMenu);
		}
	}

	if (sfFloatRect_contains(&rectEdit, mousePosMenu.x, mousePosMenu.y))
	{
		printf("yolo\n");
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			sfMusic_stop(musicMenu);
			sfMusic_play(musicEdit);
			choixJoueurMenu = EDITER;
			printf("%d\n", choixJoueurMenu);
		}
	}

	if (sfFloatRect_contains(&rectQuitter, mousePosMenu.x, mousePosMenu.y))
	{
		printf("yolo\n");
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
	sfSprite_setOrigin(SpriteEditMenu, vector2f(sfSprite_getGlobalBounds(SpriteEditMenu).width / 2, sfSprite_getGlobalBounds(SpriteEditMenu).height / 2));
	sfSprite_setOrigin(SpriteQuitterMenu, vector2f(sfSprite_getGlobalBounds(SpriteQuitterMenu).width / 2, sfSprite_getGlobalBounds(SpriteQuitterMenu).height / 2));
	sfSprite_setPosition(SpriteBackgroundMenu, pos);
	sfSprite_setPosition(SpritePlayMenu, posPlay);
	sfSprite_setPosition(SpriteEditMenu, posEdit);
	sfSprite_setPosition(SpriteQuitterMenu, posQuitter);
	sfSprite_setRotation(SpriteBackgroundMenu, angle);
	sfRenderWindow_drawSprite(_window, SpriteBackgroundMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpritePlayMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpriteEditMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpriteQuitterMenu, NULL);
}