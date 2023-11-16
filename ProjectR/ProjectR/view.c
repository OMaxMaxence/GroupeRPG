#include "view.h"

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
	if (_playerpos.x <= 115.0f && _playerpos.y <= 85.0f)
	{
		sfView_setCenter(view, vector2f(115.0f, 85.0f));
	}
	else if (_playerpos.x<=115.0f)
	{
		sfView_setCenter(view, vector2f(115.0f, _playerpos.y));

	}
	else if (_playerpos.y <= 85.0f)
	{
		sfView_setCenter(view, vector2f(_playerpos.x, 85.0f));
	}
	else sfView_setCenter(view, _playerpos);
	printf("playerpos.x : %f, playerpos.y : %f\n", _playerpos.x, _playerpos.y);
}

void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, view);
}



// EDIT VIEW

sfVector2f posEditView = { 100.0f, 100.0f };
sfFloatRect rectEditView = { 800.0f,600.0f, 1200.0f, 1200.0f };
sfVector2f speedEditView = { 200.0f, 200.0f };

void initEditView()
{
	editView = sfView_create();
	sfView_reset(editView, rectEditView);
	sfView_setCenter(editView, posEditView);
}

void updateEditView(sfVector2f _viewpos)
{
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
}

void displayEditView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, editView);
}
