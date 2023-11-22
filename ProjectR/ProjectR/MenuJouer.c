#include "MenuJouer.h"


sfSprite* SpriteBackgroundMenuJouer;
sfTexture* TextureBackgroundMenuJouer;
sfVector2f posMenuJouer = { 400.0f, 300.0f };

sfSprite* SpriteMainSaveMenuJouer;
sfTexture* TextureMainSaveMenuJouer;
sfVector2f posMainSave = { 200.0f, 450.0f };
sfFloatRect rectMainSave;

sfSprite* SpriteCustomSaveMenuJouer;
sfTexture* TextureCustomSaveMenuJouer;
sfVector2f posCustomSave = { 600.0f, 450.0f };
sfFloatRect rectCustomSave;

sfSprite* SpriteTitreMenuJouer;
sfTexture* TextureTitreMenuJouer;
sfVector2f posTitreMenuJouer = { 400.0f, 200.0f };

float delaiMenuJouer = 0.0f;
sfVector2i mousePosMenuJouer;

void initMenuJouer()
{
	SpriteBackgroundMenuJouer = sfSprite_create();
	TextureMainSaveMenuJouer = sfTexture_createFromFile(TEXTURE_PATH"MenuJouerBackgroundRPG.jpg", NULL);
	sfSprite_setTexture(SpriteBackgroundMenuJouer, TextureMainSaveMenuJouer, sfTrue);
	sfSprite_setOrigin(SpriteBackgroundMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteBackgroundMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteBackgroundMenuJouer).height / 2));
	sfSprite_setPosition(SpriteBackgroundMenuJouer, posMenuJouer);

	SpriteMainSaveMenuJouer = sfSprite_create();
	TextureBackgroundMenuJouer = sfTexture_createFromFile(TEXTURE_PATH"BlockSavePrincipal.png", NULL);
	sfSprite_setTexture(SpriteMainSaveMenuJouer, TextureBackgroundMenuJouer, sfTrue);
	sfSprite_setOrigin(SpriteMainSaveMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteMainSaveMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteMainSaveMenuJouer).height / 2));
	sfSprite_setPosition(SpriteMainSaveMenuJouer, posMainSave);

	SpriteCustomSaveMenuJouer = sfSprite_create();
	TextureCustomSaveMenuJouer = sfTexture_createFromFile(TEXTURE_PATH"BlockSaveCustom.png", NULL);
	sfSprite_setTexture(SpriteCustomSaveMenuJouer, TextureCustomSaveMenuJouer, sfTrue);
	sfSprite_setOrigin(SpriteCustomSaveMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteCustomSaveMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteCustomSaveMenuJouer).height / 2));
	sfSprite_setPosition(SpriteCustomSaveMenuJouer, posCustomSave);

	SpriteTitreMenuJouer = sfSprite_create();
	TextureTitreMenuJouer = sfTexture_createFromFile(TEXTURE_PATH"BlockTitreMenuJouer.png", NULL);
	sfSprite_setTexture(SpriteTitreMenuJouer, TextureTitreMenuJouer, sfTrue);
	sfSprite_setOrigin(SpriteTitreMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteTitreMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteTitreMenuJouer).height / 2));
	sfSprite_setPosition(SpriteTitreMenuJouer, posTitreMenuJouer);
}

void updateMenuJouer(sfRenderWindow* _window)
{
	delaiMenuJouer += getDeltaTime();
	mousePosMenuJouer = sfMouse_getPosition(_window);
	rectMainSave = sfSprite_getGlobalBounds(SpriteMainSaveMenuJouer);
	rectCustomSave = sfSprite_getGlobalBounds(SpriteCustomSaveMenuJouer);
	if (sfFloatRect_contains(&rectMainSave, mousePosMenuJouer.x, mousePosMenuJouer.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delaiMenuJouer > 0.5f && choixSave == PASCHOISIS)
		{
			delaiMenuJouer = 0.0f;
			musiqueJouer = MUSICJOUER;
			stopMusic();
			updateMusique();
			choixSave = MAINSAVE;
			initMap();
		}
	}

	else if (sfFloatRect_contains(&rectCustomSave, mousePosMenuJouer.x, mousePosMenuJouer.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delaiMenuJouer > 0.5f && choixSave == PASCHOISIS)
		{
			delaiMenuJouer = 0.0f;
			musiqueJouer = MUSICJOUER;
			stopMusic();
			updateMusique();
			choixSave = CUSTOMSAVE;
			initMap();

		}
	}
}

void displayMenuJouer(sfRenderWindow* _window)
{
	sfSprite_setOrigin(SpriteBackgroundMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteBackgroundMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteBackgroundMenuJouer).height / 2));
	sfSprite_setPosition(SpriteBackgroundMenuJouer, posMenuJouer);
	sfRenderWindow_drawSprite(_window, SpriteBackgroundMenuJouer, NULL);

	sfSprite_setOrigin(SpriteMainSaveMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteMainSaveMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteMainSaveMenuJouer).height / 2));
	sfSprite_setPosition(SpriteMainSaveMenuJouer, posMainSave);
	sfRenderWindow_drawSprite(_window, SpriteMainSaveMenuJouer, NULL);

	sfSprite_setOrigin(SpriteCustomSaveMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteCustomSaveMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteCustomSaveMenuJouer).height / 2));
	sfSprite_setPosition(SpriteCustomSaveMenuJouer, posCustomSave);
	sfRenderWindow_drawSprite(_window, SpriteCustomSaveMenuJouer, NULL);

	sfSprite_setTexture(SpriteTitreMenuJouer, TextureTitreMenuJouer, sfTrue);
	sfSprite_setOrigin(SpriteTitreMenuJouer, vector2f(sfSprite_getGlobalBounds(SpriteTitreMenuJouer).width / 2, sfSprite_getGlobalBounds(SpriteTitreMenuJouer).height / 2));
	sfSprite_setPosition(SpriteTitreMenuJouer, posTitreMenuJouer);
	sfRenderWindow_drawSprite(_window, SpriteTitreMenuJouer, NULL);
}