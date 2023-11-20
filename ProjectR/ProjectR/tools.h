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
#include "pnj.h"
#include "musique.h"
#include "key.h"
#include "chest.h"

typedef enum Menu Menu;
enum Menu
{
	MENU = 0,
	JOUER = 1,
	EDITER,
	QUITTER
};

typedef enum Musique Musique;
enum Musique
{
	NOMUSIC = 0,
	MUSICMENU = 1,
	MUSICJOUER,
	MUSICEDITER
};

Menu choixJoueurMenu;
sfRenderWindow* window;

void initTools();
float getDeltaTime();
void restartClock();
sfVector2f vector2f(float _x, float _y);
float distanceBetweenTwoPoints(sfVector2f _pos1, sfVector2f _pos2);