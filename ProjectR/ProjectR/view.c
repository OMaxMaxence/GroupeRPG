#include "view.h"

// MENU VIEW

sfVector2f posMenuView = { 400.0f,300.0f };
sfFloatRect rectMenuView = { 800.0f, 600.0f, 800.0f, 600.0f };

//Fonction initialisation view menu
void initMenuView()
{
	menuView = sfView_create();
	sfView_reset(menuView, rectMenuView);
	sfView_setCenter(menuView, posMenuView);
}

//Fonction affichage view menu
void displayMenuView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, menuView);
}



// GAME VIEW

sfVector2f posView = { 480.0f, 240.0f };
sfFloatRect rectView = { 800.0f, 600.0f, VIEW_HEIGHT, VIEW_LENGTH };

//Fonction initialisation view jeu
void initView()
{
	view = sfView_create();
	sfView_reset(view, rectView);
	sfView_setCenter(view, posView);
}
//Fonction mise à jour view jeu
void updateView(sfVector2f _playerpos)
{
	// Upper Left CORNER
	if (_playerpos.x <= 115.0f && _playerpos.y <= 85.0f)
	{
		sfView_setCenter(view, vector2f(115.0f, 85.0f));
		keyPos.x = 115.0f;
		keyPos.y = 85.0f;
	}
	// Bottom Left CORNER
	else if (_playerpos.x <= 115.0f && _playerpos.y >= MAP_HEIGHT*32 - 85.0f)
	{
		sfView_setCenter(view, vector2f(115.0f, MAP_HEIGHT * 32 - 85.0f));
		keyPos.x = 115.0f;
		keyPos.y = MAP_HEIGHT * 32 - 85.0f;
	}
	// Upper Rigth CORNER
	else if (_playerpos.x >= MAP_LENGTH * 32 - 115.0f && _playerpos.y <= 85.0f)
	{
		sfView_setCenter(view, vector2f(MAP_LENGTH * 32 - 115.0f, 85.0f));
		keyPos.x = MAP_LENGTH * 32 - 115.0f;
		keyPos.y = 85.0f;
	}
	// Bottom Right CORNER
	else if (_playerpos.x >= MAP_LENGTH * 32 - 115.0f && _playerpos.y >= MAP_HEIGHT * 32 - 85.0f)
	{
		sfView_setCenter(view, vector2f(MAP_LENGTH * 32 - 115.0f, MAP_HEIGHT * 32 - 85.0f));
		keyPos.x = MAP_LENGTH * 32 - 115.0f;
		keyPos.y = MAP_HEIGHT * 32 - 85.0f;
	}


	// Left EDGE
	else if (_playerpos.x <= 115.0f)
	{
		sfView_setCenter(view, vector2f(115.0f, _playerpos.y));
		keyPos.x = 115.0f;
		keyPos.y = _playerpos.y;
	}
	// Upper EDGE
	else if (_playerpos.y <= 85.0f)
	{
		sfView_setCenter(view, vector2f(_playerpos.x, 85.0f));
		keyPos.x = _playerpos.x;
		keyPos.y = 85.0f;
	}
	// Bottom EDGE
	else if (_playerpos.y >= MAP_HEIGHT * 32 - 85.0f)
	{
		sfView_setCenter(view, vector2f(_playerpos.x, MAP_HEIGHT * 32 - 85.0f));
		keyPos.x = _playerpos.x;
		keyPos.y = MAP_HEIGHT * 32 - 85.0f;
	}
	// Right EDGE
	else if (_playerpos.x >= MAP_LENGTH * 32 - 115.0f)
	{
		sfView_setCenter(view, vector2f(MAP_LENGTH * 32 - 115.0f, _playerpos.y));
		keyPos.x = MAP_LENGTH * 32 - 115.0f;
		keyPos.y = _playerpos.y;
	}

	// MIDDLE
	else
	{
		sfView_setCenter(view, _playerpos);
		keyPos.x = playerPos.x;
		keyPos.y = playerPos.y;
	}
}

//Fonction affichage view jeu
void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, view);
}



// EDIT VIEW

sfVector2f posEditView = { 664.0f, 464.0f };
sfFloatRect rectEditView = { 800.0f,600.0f, 1150.0f, 850.0f };
sfVector2f speedEditView = { 200.0f, 200.0f };

float timerZoom = 0.0f;

//Fonction initialisation view editeur
void initEditView()
{
	editView = sfView_create();
	sfView_reset(editView, rectEditView);
	sfView_setCenter(editView, posEditView);
}

//Fonction mise à jour view editeur
void updateEditView(sfVector2f _viewpos) 
{
	timerZoom = 0.0f;

	// Deplacement editView
	if (sfKeyboard_isKeyPressed(sfKeyD) && posEditView.x <= MAP_LENGTH * 32 - 32 * 3)
	{
		posEditView.x += speedEditView.x * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}
	else if (sfKeyboard_isKeyPressed(sfKeyZ) && posEditView.y >= 64.0f)
	{
		posEditView.y -= speedEditView.y * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}
	else if (sfKeyboard_isKeyPressed(sfKeyQ) && posEditView.x >= 96.0f)
	{
		posEditView.x -= speedEditView.x * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}
	else if (sfKeyboard_isKeyPressed(sfKeyS) && posEditView.y <= MAP_HEIGHT * 32 - 32 * 2)
	{
		posEditView.y += speedEditView.y * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}


	// Zoom editView
	timerZoom += getDeltaTime();
	if (sfKeyboard_isKeyPressed(sfKeyDown))
	{
		if (rectEditView.height < 2500.0f)
		{
			rectEditView.width *= (1.0f + timerZoom);
			rectEditView.height *= (1.0f + timerZoom);
			sfView_reset(editView, rectEditView);
			sfView_setCenter(editView, posEditView);
		}
	}
	else if (sfKeyboard_isKeyPressed(sfKeyUp))
	{
		if (rectEditView.height > 170.0f)
		{
			rectEditView.width /= (1.0f + timerZoom);
			rectEditView.height /= (1.0f + timerZoom);
			sfView_reset(editView, rectEditView);
			sfView_setCenter(editView, posEditView);
		}
	}

	// Vitesse editView selon le zoom
	speedEditView.x = rectEditView.height / 1.5f;
	speedEditView.y = rectEditView.height / 1.5f;
}

//Fonction affichage view editeur
void displayEditView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, editView);
}