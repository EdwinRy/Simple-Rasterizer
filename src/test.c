#include <stdio.h>
#include <SDL2/SDL.h>
#include "Rasterizer.h"


int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0){printf("Couldnt initialise SDL!");return -1;}

	char running = 1;
	while(running)
	{
		break;
	}
	

	SDL_Quit();
	printf("FINISHED\n");
	return 0;
}
