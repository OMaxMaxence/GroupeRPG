#include "MenuR.h"



sfSprite* SpriteBackgroundMenu;
sfTexture* TextureBackgroundMenu;
sfVector2f origin = { 400.0f, 300.0f };
sfVector2f pos = { 400.0f, 300.0f };

sfSprite* SpritePlayMenu;
sfTexture* TexturePlayMenu;
sfVector2f posPlay = { 100.0f, 450.0f };
sfFloatRect rectPlay;

sfSprite* SpriteEditMenu;
sfTexture* TextureEditMenu;
sfVector2f posEdit = { 400.0f, 450.0f };
sfFloatRect rectEdit;

sfSprite* SpriteQuitterMenu;
sfTexture* TextureQuitterMenu;
sfVector2f posQuitter = { 700.0f, 450.0f };
sfFloatRect rectQuitter;

sfSprite* SpriteTitreMenu;
sfTexture* TextureTitreMenu;
sfVector2f posTitre = { 400.0f, 200.0f };
float delai = 0.0f;

sfVector2i mousePosMenu;

//Fonction initialisation
void initMenu()
{

	SpriteBackgroundMenu = sfSprite_create();
	TextureBackgroundMenu = sfTexture_createFromFile(TEXTURE_PATH"MenuBackgroundRPG.png", NULL);
	sfSprite_setTexture(SpriteBackgroundMenu, TextureBackgroundMenu, sfTrue);
	sfSprite_setOrigin(SpriteBackgroundMenu, origin);
	sfSprite_setPosition(SpriteBackgroundMenu, pos);

	SpritePlayMenu = sfSprite_create();
	TexturePlayMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockPlay.png", NULL);
	sfSprite_setTexture(SpritePlayMenu, TexturePlayMenu, sfTrue);
	sfSprite_setOrigin(SpritePlayMenu, vector2f(sfSprite_getGlobalBounds(SpritePlayMenu).width / 2, sfSprite_getGlobalBounds(SpritePlayMenu).height / 2));
	sfSprite_setPosition(SpritePlayMenu, posPlay);

	SpriteEditMenu = sfSprite_create();
	TextureEditMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockEditer.png", NULL);
	sfSprite_setTexture(SpriteEditMenu, TextureEditMenu, sfTrue);
	sfSprite_setOrigin(SpriteEditMenu, vector2f(sfSprite_getGlobalBounds(SpriteEditMenu).width / 2, sfSprite_getGlobalBounds(SpriteEditMenu).height / 2));
	sfSprite_setPosition(SpriteEditMenu, posEdit);

	SpriteQuitterMenu = sfSprite_create();
	TextureQuitterMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockQuitter.png", NULL);
	sfSprite_setTexture(SpriteQuitterMenu, TextureQuitterMenu, sfTrue);
	sfSprite_setOrigin(SpriteQuitterMenu, vector2f(sfSprite_getGlobalBounds(SpriteQuitterMenu).width / 2, sfSprite_getGlobalBounds(SpriteQuitterMenu).height / 2));
	sfSprite_setPosition(SpriteQuitterMenu, posQuitter);

	SpriteTitreMenu = sfSprite_create();
	TextureTitreMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockTitre.png", NULL);
	sfSprite_setTexture(SpriteTitreMenu, TextureTitreMenu, sfTrue);
	sfSprite_setPosition(SpriteTitreMenu, posTitre);

	musiqueJouer = MUSICMENU;
	updateMusique();
	
}

//Fonction Mise à jour
void updateMenu(sfRenderWindow* _window, sfView* _view)
{
	delai += getDeltaTime();
	mousePosMenu = sfMouse_getPosition(_window);
	rectPlay = sfSprite_getGlobalBounds(SpritePlayMenu);
	rectEdit = sfSprite_getGlobalBounds(SpriteEditMenu);
	rectQuitter = sfSprite_getGlobalBounds(SpriteQuitterMenu);
	if (sfFloatRect_contains(&rectPlay, mousePosMenu.x, mousePosMenu.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delai > 0.5f)
		{
			delai = 0.0f;
			choixSave = 0;
			choixJoueurMenu = JOUER;
		}
	}

	else if (sfFloatRect_contains(&rectEdit, mousePosMenu.x, mousePosMenu.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delai > 0.5f)
		{
			delai = 0.0f;
			choixJoueurMenu = EDITER;
			choixContinue = PASACCEPTER;
			
		}
	}

	else if (sfFloatRect_contains(&rectQuitter, mousePosMenu.x, mousePosMenu.y) && delai > 0.3f)
	{
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			exit(EXIT_SUCCESS);
		}
	}



}

//Fonction Affichage
void displayMenu(sfRenderWindow* _window)
{
	sfSprite_setOrigin(SpriteBackgroundMenu, origin);
	sfSprite_setOrigin(SpritePlayMenu, vector2f(sfSprite_getGlobalBounds(SpritePlayMenu).width / 2, sfSprite_getGlobalBounds(SpritePlayMenu).height / 2));
	sfSprite_setOrigin(SpriteEditMenu, vector2f(sfSprite_getGlobalBounds(SpriteEditMenu).width / 2, sfSprite_getGlobalBounds(SpriteEditMenu).height / 2));
	sfSprite_setOrigin(SpriteQuitterMenu, vector2f(sfSprite_getGlobalBounds(SpriteQuitterMenu).width / 2, sfSprite_getGlobalBounds(SpriteQuitterMenu).height / 2));
	sfSprite_setOrigin(SpriteTitreMenu, vector2f(sfSprite_getGlobalBounds(SpriteTitreMenu).width / 2, sfSprite_getGlobalBounds(SpriteTitreMenu).height / 2));
	sfSprite_setPosition(SpriteBackgroundMenu, pos);
	sfSprite_setPosition(SpritePlayMenu, posPlay);
	sfSprite_setPosition(SpriteEditMenu, posEdit);
	sfSprite_setPosition(SpriteQuitterMenu, posQuitter);
	sfSprite_setPosition(SpriteTitreMenu, posTitre);
	sfRenderWindow_drawSprite(_window, SpriteBackgroundMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpritePlayMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpriteEditMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpriteQuitterMenu, NULL);
	sfRenderWindow_drawSprite(_window, SpriteTitreMenu, NULL);
}