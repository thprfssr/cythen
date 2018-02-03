#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"
#include "game.h"

#include "tiles.h"

void handle_event(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_QUIT:
			exit(-1);
			break;
		default:
			break;
	}
}

void play()
{
	SDL_Window *window = open_window(GAME_TITLE);
	SDL_Surface *window_surface = NULL;

	/* This is the representation of the gamescreen. It has the
	 * proper pixel dimensions. We will scale this surface to
	 * fit within the window.
	 */
	SDL_Surface *game_screen = create_game_screen(SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_Surface *tile_atlas = load_resource(TILE_ATLAS_PATH);

	SDL_Event event;
	int frame_counter = 0;

	while (true)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			handle_event(event);
		}

		window_surface = SDL_GetWindowSurface(window);
		SDL_FillRect(window_surface, NULL,
			     SDL_MapRGB(window_surface->format,
					0x00, 0x00, 0x00));
		SDL_FillRect(game_screen, NULL,
			     SDL_MapRGB(game_screen->format,
					0x00, 0x00, 0xff));

		SDL_Surface *tile = load_tile(tile_atlas, 16);

		letterbox(tile, window_surface);
		SDL_UpdateWindowSurface(window);

		frame_counter++;
		SDL_Delay(1000 / DESIRED_FPS);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}
