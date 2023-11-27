#include "musique.h"

//Fonction initialisation
void initMusique()
{
	musicMenu = sfMusic_createFromFile(MUSIC_PATH"Medieval-II-Total-War-Main-Menu-Background-in-4K-with-Music.ogg");   
	musicJouer = sfMusic_createFromFile(MUSIC_PATH"MusicJouer.ogg");
	musicEdit = sfMusic_createFromFile(MUSIC_PATH"Geometry-Dash-Practice-Mode-Stay-Inside-Me-Soundtrack.ogg");
	soudBoutonMenu = sfSound_create();
	soundBuffer = sfSoundBuffer_createFromFile(SOUND_PATH"Clic Sound.ogg");
	sfSound_setBuffer(soudBoutonMenu, soundBuffer);
	soundChestOpening = sfSound_create();
	chestSoundBuffer = sfSoundBuffer_createFromFile(SOUND_PATH"Chest-Opening.ogg");
	sfSound_setBuffer(soundChestOpening, chestSoundBuffer);

}

//Fonction mise à jour
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

//Fonction affichage
void stopMusic()
{
	sfMusic_stop(musicMenu);
	sfMusic_stop(musicJouer);
	sfMusic_stop(musicEdit);
}