#include "view.h"

sfVector2f posView = { 480.0f, 240.0f };
sfFloatRect rectView = { 100.0f, 100.0f, 230.0f, 170.0f };

void initView()
{
	view = sfView_create();
	sfView_reset(view, rectView);
	sfView_setCenter(view, posView);
}

void updateView(sfVector2f _playerpos)
{
	//if !bord
	sfView_setCenter(view, _playerpos);
}

void displayView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, view);
}
