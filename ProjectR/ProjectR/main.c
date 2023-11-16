#include "tools.h"
typedef enum Menu Menu;
enum Menu
{
	JOUER = 1,
	EDITER,
	QUITTER
};

int main()
{
	sfVideoMode mode = { 800, 600, 32 };

	char titre[100];
	sprintf_s(titre, 100, "TEST");

	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, titre, sfDefaultStyle, NULL);
	sfEvent event;

	float timer = 0;
	float timerAnim = 0;
	initTools();
	initPlayer();
	//initMenu();


	initMap();
	initView();
	//initEditView();


	while (sfRenderWindow_isOpen(window))
	{
		restartClock();
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}



		//updateMenu(window, view);
		updatePlayer();
		updateMap(window, timerAnim, view);
		updateView(playerPos);
		//updateEditView(posEditView);




		/*timer += 0.1f * getDeltaTime();
		if (timer >= 4.0f) timer = 0;
		timerAnim += 0.001f * getDeltaTime();
		if (timerAnim >= 4.0f) timerAnim = 0;*/
		sfRenderWindow_clear(window, sfBlack);
		//displayMenu(window);
		displayView(window);
		//displayEditView(window);
		displayMap(window, timerAnim);
		displayPlayer(window);
		sfRenderWindow_display(window);
	}

	return 0;
}