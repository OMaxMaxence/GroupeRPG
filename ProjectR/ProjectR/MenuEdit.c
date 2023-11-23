#include"MenuEdit.h"

sfSprite* SpriteBackgroundMenuEdit;
sfTexture* TextureBackgroundMenuEdit;
sfVector2f posMenuEdit = { 400.0f, 300.0f };

sfSprite* SpriteMenuEditCondition;
sfTexture* TextureMenuEditCondition;
sfVector2f posCondition = { 400.0f, 150.0f };

sfSprite* SpriteMenuEditContinue;
sfTexture* TextureMenuEditContinue;
sfVector2f posContinue = { 400.0f, 500.0f };
sfFloatRect rectContinue;



float delaiMenuEdit = 0.0f;
sfVector2i mousePosMenuEdit;

void initMenuEdit()
{
	TextureBackgroundMenuEdit = sfTexture_createFromFile(TEXTURE_PATH"MenuJouerBackgroundRPG.jpg", NULL);
	SpriteBackgroundMenuEdit = creaSprite(SpriteBackgroundMenuEdit, TextureBackgroundMenuEdit, posMenuEdit);
	

	TextureMenuEditCondition = sfTexture_createFromFile(TEXTURE_PATH"BlockMenuEditCondition.png", NULL);
	SpriteMenuEditCondition = creaSprite(SpriteMenuEditCondition, TextureMenuEditCondition, posCondition);


	TextureMenuEditContinue = sfTexture_createFromFile(TEXTURE_PATH"BlockContinue.png", NULL);
	SpriteMenuEditContinue = creaSprite(SpriteMenuEditContinue, TextureMenuEditContinue, posContinue);

}

void updateMenuEdit(sfRenderWindow* _window)
{
	delaiMenuEdit += getDeltaTime();
	mousePosMenuEdit = sfMouse_getPosition(_window);
	rectContinue = sfSprite_getGlobalBounds(SpriteMenuEditContinue);

	if (sfFloatRect_contains(&rectContinue, mousePosMenuEdit.x, mousePosMenuEdit.y))
	{
		if (sfMouse_isButtonPressed(sfMouseLeft) && delaiMenuEdit > 0.5f)
		{
			delaiMenuEdit = 0.0f;
			editeur = sfTrue;
			musiqueJouer = MUSICEDITER;
			stopMusic();
			updateMusique();
			choixContinue = ACCEPTER;
			
		}
	}
}

void displayMenuEdit(sfRenderWindow* _window)
{
	sfSprite_setOrigin(SpriteBackgroundMenuEdit, vector2f(sfSprite_getGlobalBounds(SpriteBackgroundMenuEdit).width / 2, sfSprite_getGlobalBounds(SpriteBackgroundMenuEdit).height / 2));
	sfSprite_setPosition(SpriteBackgroundMenuEdit, posMenuEdit);
	sfRenderWindow_drawSprite(_window, SpriteBackgroundMenuEdit, NULL);

	sfSprite_setOrigin(SpriteMenuEditCondition, vector2f(sfSprite_getGlobalBounds(SpriteMenuEditCondition).width / 2, sfSprite_getGlobalBounds(SpriteMenuEditCondition).height / 2));
	sfSprite_setPosition(SpriteMenuEditCondition, posCondition);
	sfRenderWindow_drawSprite(_window, SpriteMenuEditCondition, NULL);

	sfSprite_setOrigin(SpriteMenuEditContinue, vector2f(sfSprite_getGlobalBounds(SpriteMenuEditContinue).width / 2, sfSprite_getGlobalBounds(SpriteMenuEditContinue).height / 2));
	sfSprite_setPosition(SpriteMenuEditContinue, posContinue);
	sfRenderWindow_drawSprite(_window, SpriteMenuEditContinue, NULL);

}
