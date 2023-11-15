#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "SFML/Graphics.h"
#include <math.h>
#include <time.h>
#include "SFML/Window.h"
#include"SFML/Audio.h"
#include "MenuR.h"
#include "map.h"
#include "MenuR.h"
#include "player.h"
#include "view.h"

sfRenderWindow* window;

void initTools();
float getDeltaTime();
void restartClock();
sfVector2f vector2f(float _x, float _y);