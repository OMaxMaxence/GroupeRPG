#include "view.h"

// MENU VIEW

sfVector2f posMenuView = { 400.0f,300.0f };
sfFloatRect rectMenuView = { 800.0f, 600.0f, 800.0f, 600.0f };

void initMenuView()
{
	menuView = sfView_create();
	sfView_reset(menuView, rectMenuView);
	sfView_setCenter(menuView, posMenuView);
}

void displayMenuView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, menuView);
}

// GAME VIEW

sfVector2f posView = { 480.0f, 240.0f };
sfFloatRect rectView = { 800.0f, 600.0f, VIEW_HEIGHT, VIEW_LENGTH };

void initView()
{
	view = sfView_create();
	sfView_reset(view, rectView);
	sfView_setCenter(view, posView);
}

void updateView(sfVector2f _playerpos)
{
	if (_playerpos.x <= 115.0f && _playerpos.y <= 85.0f) // Upper Left CORNER
	{
		sfView_setCenter(view, vector2f(115.0f, 85.0f));
	}
	else if (_playerpos.x <= 115.0f && _playerpos.y >= MAP_HEIGHT*32 - 85.0f) // Bottom Left CORNER
	{
		sfView_setCenter(view, vector2f(115.0f, MAP_HEIGHT*32 - 85.0f));
	}
	else if (_playerpos.x >= MAP_LENGTH*32 - 115.0f && _playerpos.y <= 85.0f) // Upper Rigth CORNER
	{
		sfView_setCenter(view, vector2f(MAP_LENGTH*32 - 115.0f, 85.0f));
	}
	else if (_playerpos.x >= MAP_LENGTH*32 - 115.0f && _playerpos.y >= MAP_HEIGHT*32 - 85.0f) // Bottom Right CORNER
	{
		sfView_setCenter(view, vector2f(MAP_LENGTH*32 - 115.0f, MAP_HEIGHT*32 - 85.0f));
	}
	else if (_playerpos.x<=115.0f) // Left EDGE
	{
		sfView_setCenter(view, vector2f(115.0f, _playerpos.y));
	}
	else if (_playerpos.y <= 85.0f) // Upper EDGE
	{
		sfView_setCenter(view, vector2f(_playerpos.x, 85.0f));
	}
	else if (_playerpos.y >= MAP_HEIGHT*32 - 85.0f) // Bottom EDGE
	{
		sfView_setCenter(view, vector2f(_playerpos.x, MAP_HEIGHT*32 - 85.0f));
	}
	else if (_playerpos.x >= MAP_LENGTH*32 - 115.0f) // Right EDGE
	{
		sfView_setCenter(view, vector2f(MAP_LENGTH * 32 - 115.0f, _playerpos.y));
	}
	else sfView_setCenter(view, _playerpos);
}

void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, view);
}



// EDIT VIEW

sfVector2f posEditView = { 100.0f, 100.0f };
sfFloatRect rectEditView = { 800.0f,600.0f, 1150.0f, 850.0f };
sfVector2f speedEditView = { 200.0f, 200.0f };

void initEditView()
{
	editView = sfView_create();
	sfView_reset(editView, rectEditView);
	sfView_setCenter(editView, posEditView);
}

void updateEditView(sfVector2f _viewpos)
{
	// Deplacement editView
	if (sfKeyboard_isKeyPressed(sfKeyD))
	{
		posEditView.x += speedEditView.x * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}
	else if (sfKeyboard_isKeyPressed(sfKeyZ))
	{
		posEditView.y -= speedEditView.y * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}
	else if (sfKeyboard_isKeyPressed(sfKeyQ))
	{
		posEditView.x -= speedEditView.x * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}
	else if (sfKeyboard_isKeyPressed(sfKeyS))
	{
		posEditView.y += speedEditView.y * getDeltaTime();
		sfView_setCenter(editView, posEditView);
	}


	// Zoom editView
	if (sfKeyboard_isKeyPressed(sfKeyDown))
	{
		if (rectEditView.height < 2500.0f)
		{
			rectEditView.width *= 1.002f;
			rectEditView.height *= 1.002f;
			sfView_reset(editView, rectEditView);
			sfView_setCenter(editView, posEditView);
		}
	}
	else if (sfKeyboard_isKeyPressed(sfKeyUp))
	{
		if (rectEditView.height > 200.0f)
		{
			rectEditView.width *= 0.998f;
			rectEditView.height *= 0.998f;
			sfView_reset(editView, rectEditView);
			sfView_setCenter(editView, posEditView);
		}
	}


	// Vitesse editView selon le zoom
	speedEditView.x = rectEditView.height / 1.5f;
	speedEditView.y = rectEditView.height / 1.5f;
}

void displayEditView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, editView);
}
