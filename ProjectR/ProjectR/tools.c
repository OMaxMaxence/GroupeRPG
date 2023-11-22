#include "tools.h"

sfTime sftime;
sfClock* sfclock;

//Fonction initialisation
void initTools()
{
	sfclock = sfClock_create();
	srand(time(NULL));
}

//Fonction convertion du temps matériel en seconde
float getDeltaTime()
{
	return sfTime_asSeconds(sftime);
}

//Fonction pour l'horloge
void restartClock()
{
	sftime = sfClock_restart(sfclock);
}


sfVector2f vector2f(float _x, float _y)
{
	sfVector2f v = { _x, _y };
	return v;
}

//Fonction pour calcul de distance entre 2 points
float distanceBetweenTwoPoints(sfVector2f _pos1, sfVector2f _pos2)
{
	float d = sqrtf((_pos2.x - _pos1.x) * (_pos2.x - _pos1.x) + (_pos2.y - _pos1.y) * (_pos2.y - _pos1.y));
	return d;
}


