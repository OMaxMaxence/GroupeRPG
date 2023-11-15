#pragma once
#include "tools.h"

sfView* view;
sfVector2f posView;
sfFloatRect rectView;

sfVector2i pixelPos;
sfVector2f worldPos;

void initView();
void updateView(sfVector2f _playerpos);
void displayView(sfRenderWindow* _window);