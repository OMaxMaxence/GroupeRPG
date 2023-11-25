#include "MenuR.h"

sfSprite* SpriteBackgroundMenu;
sfTexture* TextureBackgroundMenu;
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
float delai_menuJouer = 0.0f;
float delai_menu = 0.0f;

sfVector2i mousePosMenu;

//Fonction initialisation
void initMenu()
{
	// Fond
	TextureBackgroundMenu = sfTexture_createFromFile(TEXTURE_PATH"MenuBackgroundRPG.png", NULL);
	SpriteBackgroundMenu = creaSprite(SpriteBackgroundMenu, TextureBackgroundMenu, pos);

	// Bloc Jouer
	TexturePlayMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockPlay.png", NULL);
	SpritePlayMenu = creaSprite(SpritePlayMenu, TexturePlayMenu, posPlay);

	// Bloc Editer
	TextureEditMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockEditer.png", NULL);
	SpriteEditMenu = creaSprite(SpritePlayMenu, TextureEditMenu, posEdit);

	// Bloc Quitter
	TextureQuitterMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockQuitter.png", NULL);
	SpriteQuitterMenu = creaSprite(SpriteQuitterMenu, TextureQuitterMenu, posEdit);

	// Titre
	TextureTitreMenu = sfTexture_createFromFile(TEXTURE_PATH"BlockTitre.png", NULL);
	SpriteTitreMenu = creaSprite(SpriteTitreMenu, TextureTitreMenu, posTitre);

	musiqueJouer = MUSICMENU;
	updateMusique();
	
}

//Fonction Mise à jour
void updateMenu(sfRenderWindow* _window, sfView* _view)
{
	delai_menuJouer += getDeltaTime();
	delai_menu = 0.0f;
	mousePosMenu = sfMouse_getPosition(_window);
	rectPlay = sfSprite_getGlobalBounds(SpritePlayMenu);
	rectEdit = sfSprite_getGlobalBounds(SpriteEditMenu);
	rectQuitter = sfSprite_getGlobalBounds(SpriteQuitterMenu);

	// Jouer
	if (sfFloatRect_contains(&rectPlay, mousePosMenu.x, mousePosMenu.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delai_menuJouer > 0.5f)
		{
			delai_menuJouer = 0.0f;
			choixSave = 0;
			choixJoueurMenu = JOUER;
		}
	}

	// Éditer
	else if (sfFloatRect_contains(&rectEdit, mousePosMenu.x, mousePosMenu.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delai_menuJouer > 0.5f)
		{
			delai_menuJouer = 0.0f;
			choixJoueurMenu = EDITER;
			choixContinue = PASACCEPTER;
			
		}
	}

	// Quitter
	else if (sfFloatRect_contains(&rectQuitter, mousePosMenu.x, mousePosMenu.y) && delai_menuJouer > 0.3f)
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
	// Fond
	sfSprite_setOrigin(SpriteBackgroundMenu, vector2f(sfSprite_getGlobalBounds(SpriteBackgroundMenu).width / 2, sfSprite_getGlobalBounds(SpriteBackgroundMenu).height / 2));
	sfSprite_setPosition(SpriteBackgroundMenu, pos);
	sfRenderWindow_drawSprite(_window, SpriteBackgroundMenu, NULL);

	// Bouton Jouer
	sfSprite_setOrigin(SpritePlayMenu, vector2f(sfSprite_getGlobalBounds(SpritePlayMenu).width / 2, sfSprite_getGlobalBounds(SpritePlayMenu).height / 2));
	sfSprite_setPosition(SpritePlayMenu, posPlay);
	sfRenderWindow_drawSprite(_window, SpritePlayMenu, NULL);

	// Bouton Édit
	sfSprite_setOrigin(SpriteEditMenu, vector2f(sfSprite_getGlobalBounds(SpriteEditMenu).width / 2, sfSprite_getGlobalBounds(SpriteEditMenu).height / 2));
	sfSprite_setPosition(SpriteEditMenu, posEdit);
	sfRenderWindow_drawSprite(_window, SpriteEditMenu, NULL);
	
	// Bouton Quitter
	sfSprite_setOrigin(SpriteQuitterMenu, vector2f(sfSprite_getGlobalBounds(SpriteQuitterMenu).width / 2, sfSprite_getGlobalBounds(SpriteQuitterMenu).height / 2));
	sfSprite_setPosition(SpriteQuitterMenu, posQuitter);
	sfRenderWindow_drawSprite(_window, SpriteQuitterMenu, NULL);

	// Titre
	sfSprite_setOrigin(SpriteTitreMenu, vector2f(sfSprite_getGlobalBounds(SpriteTitreMenu).width / 2, sfSprite_getGlobalBounds(SpriteTitreMenu).height / 2));
	sfSprite_setPosition(SpriteTitreMenu, posTitre);
	sfRenderWindow_drawSprite(_window, SpriteTitreMenu, NULL);
}