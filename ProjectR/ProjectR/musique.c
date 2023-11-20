#include "musique.h"


void initMusique()
{
	musicMenu = sfMusic_createFromFile("..\\Ressources\\Musics\\Medieval-II-Total-War-Main-Menu-Background-in-4K-with-Music.ogg");
	musicJouer = sfMusic_createFromFile("..\\Ressources\\Musics\\MusicJouer.ogg");
	musicEdit = sfMusic_createFromFile("..\\Ressources\\Musics\\Geometry-Dash-Practice-Mode-Stay-Inside-Me-Soundtrack.ogg");


}

void updateMusique()
{
	if (musiqueJouer == MUSICMENU) 
	{
		sfMusic_play(musicMenu);
	}

	else if (musiqueJouer == MUSICJOUER)
	{
		sfMusic_play(musicJouer);
	}

	else if (musiqueJouer == MUSICEDITER)
	{
		sfMusic_play(musicEdit);
	}
}

void stopMusic()
{
	sfMusic_stop(musicMenu);
	sfMusic_stop(musicJouer);
	sfMusic_stop(musicEdit);
}