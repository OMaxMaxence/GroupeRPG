#include "musique.h"


void initMusique()
{
	musicMenu = sfMusic_createFromFile("..\\Ressources\\Musics\\Medieval-II-Total-War-Main-Menu-Background-in-4K-with-Music.ogg");
	musicJouer = sfMusic_createFromFile("..\\Ressources\\Musics\\MusicJouer.ogg");
	musicEdit = sfMusic_createFromFile("..\\Ressources\\Musics\\Geometry-Dash-Practice-Mode-Stay-Inside-Me-Soundtrack.ogg");
	soudBoutonMenu = sfSound_create();
	soundBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\Clic Sound.ogg");
	sfSound_setBuffer(soudBoutonMenu, soundBuffer);

}

void updateMusique()
{
	if (musiqueJouer == MUSICMENU) 
	{
		sfSound_play(soudBoutonMenu);
		sfMusic_play(musicMenu);
		sfMusic_setLoop(musicMenu, sfTrue);
	}

	else if (musiqueJouer == MUSICJOUER)
	{
		sfSound_play(soudBoutonMenu);
		sfMusic_play(musicJouer);
		sfMusic_setLoop(musicJouer, sfTrue);
	}

	else if (musiqueJouer == MUSICEDITER)
	{
		sfSound_play(soudBoutonMenu);
		sfMusic_play(musicEdit);
		sfMusic_setLoop(musicEdit, sfTrue);
	}
}

void stopMusic()
{
	sfMusic_stop(musicMenu);
	sfMusic_stop(musicJouer);
	sfMusic_stop(musicEdit);
}