#include <stdio.h>
#include <SDL2/SDL.h>
#include "Rasterizer.h"

int main()
{
	char* title = "title";
	int width = 500;
	int height = 500;

	//SDL init
	if(SDL_Init(SDL_INIT_VIDEO) != 0){printf("Couldnt initialise SDL!");return -1;}
	
	SDL_Window* window = SDL_CreateWindow(
		title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_STREAMING, width, height);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Event event;

	//Renderer init
	Screen* screen = createScreen(width,height);	
	Rasterizer* rasterizer = createRasterizer(screen);
	
	//Testing	
	


	char running = 1;
	while(running)
	{
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){running = 0; break;}}

		//Do rendering here
		setPixel(rasterizer,255,255,   255,0,0,255);

		//Stop rendering
		SDL_UpdateTexture(texture,NULL, screen->pixels + 0, width * 4);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);

		SDL_RenderClear(renderer);
	}
	

	SDL_Quit();
	printf("FINISHED\n");
	return 0;
}
