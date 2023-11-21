#include "BlockText.h"
#include "pnj.h"

sfRectangleShape* rectangle;
sfText* consigne;
char* consigneChar = "Bonjour aventurier, \ntrouve les coffres sacres  \nainsi, tu reuniras les 3 fragements de la cle du temps, \npour ouvrir la porte millenaire, \nqui liberera la princesse clefda";
sfFont* consigneFont;
sfVector2f rectsize = { 100.0f, 25.0f };
sfVector2f rectanglePos = { 0.0f, 0.0f };
sfVector2f txtsize = {0.15f, 0.15f };
sfVector2f txtPos = { 0.0f, 0.0f};

void initBlockText()
{
	rectangle = sfRectangleShape_create();

	//sfRectangleShape_setSize(rectangle, rectsize);
	//sfRectangleShape_setPosition(rectangle, rectanglePos);
	//sfRectangleShape_setOrigin(rectangle, vector2f(sfSprite_getGlobalBounds(rectangle).width / 2, sfSprite_getGlobalBounds(rectangle).height / 2));
	//sfRectangleShape_setFillColor(rectangle, sfBlack);
	consigne = sfText_create();
	consigneFont = sfFont_createFromFile(FONT_PATH"The Wild Breath of Zelda.otf");
	/*sfText_setFont(consigne, consigneFont);
	sfText_setString(consigne, consigneChar);
	sfText_setScale(consigne, txtsize);*/
}

void updateBlockText()
{

}

void displayBlockText(sfRenderWindow* _window)
{
	sfVector2f rectanglePos = { pnjPos.x, pnjPos.y - 40};
	sfVector2f txtPos = { pnjPos.x, pnjPos.y - 40 };
	sfRectangleShape_setFillColor(rectangle, sfBlack);
	sfRectangleShape_setSize(rectangle, rectsize);
	sfRectangleShape_setOrigin(rectangle, vector2f(sfSprite_getGlobalBounds(rectangle).width / 2, sfSprite_getGlobalBounds(rectangle).height / 2));
	sfRectangleShape_setPosition(rectangle, rectanglePos);
	sfRenderWindow_drawRectangleShape(_window, rectangle, NULL);
	sfText_setFont(consigne, consigneFont);
	sfText_setString(consigne, consigneChar);
	sfText_setScale(consigne, txtsize);
	sfText_setPosition(consigne, txtPos);
	sfRenderWindow_drawText(_window, consigne, NULL);
}