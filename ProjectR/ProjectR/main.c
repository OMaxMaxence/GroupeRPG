#include "tools.h"



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
	initMenu();
	initMap();
	initPlayer();
	initMenuView();
	initView();
	initEditView();
	initPnj();
	choixJoueurMenu = MENU;


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


		if (sfKeyboard_isKeyPressed(sfKeyB))
		{
			if (timer == 0)
			{
				choixJoueurMenu = MENU;
			}
			timer = 1;
		}
		else 
		{
			timer = 0;
		}

		if (choixJoueurMenu == MENU)
		{
			updateMenu(window, view);
		}

		else if (choixJoueurMenu == JOUER)
		{
			displayPnj(window);
			updatePlayer();
			updateView(playerPos);
		}

		else if (choixJoueurMenu == EDITER)
		{
			updateMap(window, timerAnim, view);
			updateEditView(posEditView);
		}


		/*timer += 0.1f * getDeltaTime();
		if (timer >= 4.0f) timer = 0;
		timerAnim += 0.001f * getDeltaTime();
		if (timerAnim >= 4.0f) timerAnim = 0;*/
		sfRenderWindow_clear(window, sfBlack);
		if (choixJoueurMenu == MENU)
		{
			displayMenu(window);
			displayMenuView(window);
		}

		else if (choixJoueurMenu == JOUER)
		{
			displayView(window);
			displayMap(window, timerAnim);
			displayPnj(window);
			displayPlayer(window);
		}

		else if (choixJoueurMenu == EDITER)
		{
			displayMap(window, timerAnim);
			displayEditView(window);
		}
		
		sfRenderWindow_display(window);
	}

	return 0;
}