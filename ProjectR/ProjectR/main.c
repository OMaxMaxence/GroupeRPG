#include "tools.h"


int main()
{
	sfVideoMode mode = { 800, 600, 32 };

	char titre[100];
	sprintf_s(titre, 100, "TEST");

	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, titre, sfFullscreen, NULL);
	sfEvent event;
	while (sfRenderWindow_isOpen(window))
	{

		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}

		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display(window);
	}
}