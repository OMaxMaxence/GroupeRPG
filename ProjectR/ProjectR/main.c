#include "tools.h"



int main()
{
	sfVideoMode mode = { 800, 600, 32 };

	char titre[100];
	sprintf_s(titre, 100, "Plink Quest, the key seeker of the past");

	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, titre, sfDefaultStyle, NULL);
	sfEvent event;

	float timer = 0;
	float timerAnim = 0;
	
	initTools();
	initMusique();
	initMenu();
	initMap();
	initPlayer();
	initMenuView();
	initView();
	initEditView();
	initPnj();
	initBlockText();

	choixJoueurMenu = MENU;

	//Boucle de jeu
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

		//Mise à jour
		timer += getDeltaTime();
		//Retour au menu via touche
		if (sfKeyboard_isKeyPressed(sfKeyEscape) && choixJoueurMenu != MENU && timer > 1.0f)
		{
			timer = 0.0f;
			sfRenderWindow_setMouseCursorVisible(window, sfTrue);
			stopMusic();
			choixJoueurMenu = MENU;
			initMenu();
			displayMenuView(window);

		}

		if (choixJoueurMenu == MENU)
		{
			updateMenu(window, view);
		}

		//Mode jouer
		else if (choixJoueurMenu == JOUER)
		{
			initMap();
			updateGameMap(window, timerAnim, view); 
			updatePnj();
			updatePlayer();
			
			updateView(playerPos);
			//sfRenderWindow_setMouseCursorVisible(window, sfFalse);
		}

		//Mode Editeur
		else if (choixJoueurMenu == EDITER)
		{
			updateMap(window, timerAnim, view);
			updateEditView(posEditView);
		}

		

		//Affichage

		sfRenderWindow_clear(window, sfBlack);
		if (choixJoueurMenu == MENU)
		{
			displayMenu(window);
			displayMenuView(window);
		}

		else if (choixJoueurMenu == JOUER)
		{
			displayView(window);
			displayGameMap(window, timerAnim); 
			displayPnj(window);
			displayPlayer(window);
			displayBlockText(window);
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

