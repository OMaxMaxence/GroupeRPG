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
		initMenu();
		initMap();
		


		/*timer += 0.1f * getDeltaTime();
		if (timer >= 4.0f) timer = 0;
		timerAnim += 0.001f * getDeltaTime();
		if (timerAnim >= 4.0f) timerAnim = 0;*/
		sfRenderWindow_clear(window, sfBlack);
		displayMenu(window);
		displayMap(window, timerAnim);
		sfRenderWindow_display(window);
	}
}