#pragma once
#include "tools.h"

// GAME VIEW

sfView* view;
sfVector2f posView;
sfFloatRect rectView;

sfVector2i pixelPos;
sfVector2f worldPos;

void initView();
void updateView(sfVector2f _playerpos);
void displayView(sfRenderWindow* _window);

// EDIT VIEW

sfView* editView;
sfVector2f posEditView;
sfFloatRect rectEditView;

sfVector2i pixelEditPos;
sfVector2f worldEditPos;

void initEditView();
void updateEditView(sfVector2f _viewpos);
void displayEditView(sfRenderWindow* _window);