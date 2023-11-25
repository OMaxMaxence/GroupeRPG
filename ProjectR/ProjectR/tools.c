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

//Fonction création d'un sfVector2f plus facilement
sfVector2f vector2f(float _x, float _y)
{
	sfVector2f v = { _x, _y };
	return v;
}

//Fonction de calcul de distance entre 2 points
float distanceBetweenTwoPoints(sfVector2f _pos1, sfVector2f _pos2)
{
	float d = sqrtf((_pos2.x - _pos1.x) * (_pos2.x - _pos1.x) + (_pos2.y - _pos1.y) * (_pos2.y - _pos1.y));
	return d;
}

//Fonction de création de Sprite plus lisible et plus facilement
sfSprite* creaSprite(sfSprite* _sprite, sfTexture* _texture, sfVector2f _posSprite)
{
	_sprite = sfSprite_create();
	sfSprite_setTexture(_sprite, _texture, sfTrue);
	sfSprite_setOrigin(_sprite, vector2f(sfSprite_getGlobalBounds(_sprite).width / 2, sfSprite_getGlobalBounds(_sprite).height / 2));
	sfSprite_setPosition(_sprite, _posSprite);
	return _sprite;
}