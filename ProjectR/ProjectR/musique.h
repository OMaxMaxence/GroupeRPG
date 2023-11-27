#pragma once
#include "tools.h"

sfMusic* musicMenu;
sfMusic* musicEdit;
sfMusic* musicJouer;
sfSound* soudBoutonMenu;
sfSoundBuffer* soundBuffer;
sfSound* soundChestOpening;
sfSoundBuffer* chestSoundBuffer;

//prototype fonction
void initMusique();
void updateMusique();
void stopMusic();
