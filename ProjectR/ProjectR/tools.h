#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
#include "BlockText.h"
#include "key.h"
#include "chest.h"
#include "porte.h"
#include "MenuJouer.h"
#define TEXTURE_PATH "../Ressources/Textures/" 
#define MUSIC_PATH "../Ressources/Musics/"
#define SOUND_PATH "../Ressources/SoundsFX/"
#define FONT_PATH "../Ressources/Fonts/"

typedef enum Menu Menu;
enum Menu
{
	MENU = 0,
	JOUER = 1,
	EDITER,
	QUITTER
};

typedef enum MenuJouer MenuJouer;
enum MenuJouer
{
	PASCHOISIS = 0,
	MAINSAVE = 1,
	CUSTOMSAVE
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
MenuJouer choixSave;
//sfRenderWindow* window;

void initTools();
float getDeltaTime();
void restartClock();
sfVector2f vector2f(float _x, float _y);
float distanceBetweenTwoPoints(sfVector2f _pos1, sfVector2f _pos2);