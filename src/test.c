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

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
		|| SDL_RENDERER_PRESENTVSYNC);
	
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_STREAMING, width, height);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Event event;

	//Renderer init
	Screen* screen = createScreen(width,height);	
	Rasterizer* rasterizer = createRasterizer(screen);
	
	//Testing	
	Vec3f * v1 = createVec3f(-0.5,0.5,0);
	Vec3f * v2 = createVec3f(-0.5,-0.5,0);
	Vec3f * v3 = createVec3f(0.5,-0.5,0);
	Vec3f * v4 = createVec3f(0.5,0.5,0);	
	Vec3f ** vs = malloc(sizeof(Vec3f*)*4);
	vs[0] = v1;
	vs[1] = v2;
	vs[2] = v3;
	vs[3] = v4;

	int * in = malloc(sizeof(int*)*6);
	in[0] = 0;		
	in[1] = 1;
	in[2] = 2;
	in[3] = 0;
	in[4] = 2;
	in[5] = 3;

	//convertCoordToVec3f(rasterizer,

	loadCoords(rasterizer, vs, 4);
	loadIndices(rasterizer, in, 6);

	char running = 1;
	while(running)
	{
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){running = 0; break;}}

		//Start rendering here	
			
		drawIndices(rasterizer);
		//drawTriangles(rasterizer);
		//Stop rendering
		SDL_UpdateTexture(texture,NULL,
			 screen->pixels + 0, width * 4);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
		SDL_RenderClear(renderer);
	}
	

	SDL_Quit();
	printf("FINISHED\n");
	return 0;
}
