#include "musique.h"


initMusique()
{
	musicMenu = sfMusic_createFromFile("..\\Ressources\\Musics\\Medieval-II-Total-War-Main-Menu-Background-in-4K-with-Music.ogg");
	musicEdit = sfMusic_createFromFile("..\\Ressources\\Musics\\Geometry-Dash-Practice-Mode-Stay-Inside-Me-Soundtrack.ogg");
	musicJouer = sfMusic_createFromFile("..\\Ressources\\Musics\\MusicJouer.ogg");

}

updateMusique()
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

stopMusic()
{
	sfMusic_stop(musicMenu);
	sfMusic_stop(musicJouer);
	sfMusic_stop(musicEdit);
}