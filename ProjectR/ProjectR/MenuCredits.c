#include "MenuCredits.h"

sfSprite* SpriteBackgroundCredits;
sfTexture* TextureBackgroundCredits;
sfVector2f posMenuCredits = { 400.0f, 300.0f };
sfIntRect rectCredits = { 0,0,800,600 };

sfSprite* SpriteMenuCreditsQuitter;
sfTexture* TextureMenuCreditsQuitter;
sfVector2f posCreditsQuitter = { 400.0f, 500.0f };
sfFloatRect rectQuitter;

float delaiMenuCredits = 0.0f;
float timerAnimCredits;
sfVector2i mousePosMenuCredits;

void initMenuCredits()
{
	timerAnimCredits = 0.0f;
	delaiMenuCredits = 0.0f;
	rectCredits.left = 0;

	// Fond
	TextureBackgroundCredits = sfTexture_createFromFile(TEXTURE_PATH"BackgroundRPG_FIN.png", NULL);
	SpriteBackgroundCredits = creaSprite(SpriteBackgroundCredits, TextureBackgroundCredits, posMenuCredits);
	sfSprite_setTextureRect(SpriteBackgroundCredits, rectCredits);

	// Bloc Quitter
	TextureMenuCreditsQuitter = sfTexture_createFromFile(TEXTURE_PATH"BlockQuitter.png", NULL);
	SpriteMenuCreditsQuitter = creaSprite(SpriteMenuCreditsQuitter, TextureMenuCreditsQuitter, posCreditsQuitter);


}

void updateMenuCredits(sfRenderWindow* _window)
{

	// Sprite du fond
	timerAnimCredits += getDeltaTime();
	if (timerAnimCredits > 0.5f && rectCredits.left < 3200)
	{
		rectCredits.left += 800;
		timerAnimCredits = 0.0f;
		sfSprite_setTextureRect(SpriteBackgroundCredits, rectCredits);
	}


	delaiMenuCredits += getDeltaTime();
	mousePosMenuCredits = sfMouse_getPosition(_window);
	rectQuitter = sfSprite_getGlobalBounds(SpriteMenuCreditsQuitter);


	// Quitter
	if (sfFloatRect_contains(&rectQuitter, mousePosMenuCredits.x, mousePosMenuCredits.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delaiMenuCredits > 0.5f && rectCredits.left >= 3200)
		{
			delaiMenuCredits = 0.0f;
			choixJoueurMenu = MENU;
			initMenuCredits();
		}
	}
}

void displayMenuCredits(sfRenderWindow* _window)
{
	//Fond
	sfSprite_setOrigin(SpriteBackgroundCredits, vector2f(sfSprite_getGlobalBounds(SpriteBackgroundCredits).width / 2, sfSprite_getGlobalBounds(SpriteBackgroundCredits).height / 2));
	sfSprite_setPosition(SpriteBackgroundCredits, posMenuCredits);
	sfRenderWindow_drawSprite(_window, SpriteBackgroundCredits, NULL);

	// Bouton Quitter (Uniqement au dernier Sprite du fond)
	if (rectCredits.left >= 3200)
	{
		sfSprite_setOrigin(SpriteMenuCreditsQuitter, vector2f(sfSprite_getGlobalBounds(SpriteMenuCreditsQuitter).width / 2, sfSprite_getGlobalBounds(SpriteMenuCreditsQuitter).height / 2));
		sfSprite_setPosition(SpriteMenuCreditsQuitter, posCreditsQuitter);
		sfRenderWindow_drawSprite(_window, SpriteMenuCreditsQuitter, NULL);
	}

}
