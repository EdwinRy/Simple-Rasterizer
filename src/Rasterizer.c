#include "Rasterizer.h"

void setPixel(Rasterizer* rasterizer,
float x, float y, char r, char g, char b)
{


}

Screen* createScreen(int width, int height)
{
	Screen* screen = malloc(sizeof(Screen));
	screen->width = width;
	screen->height = height;
	screen->pixels = malloc(width*height*4);	
	return screen;
}

Rasterizer* createRasterizer(Screen* screen)
{
	Rasterizer * rasterizer = malloc(sizeof(Rasterizer));	
	rasterizer->screen = screen;
	rasterizer->depthBuffer = malloc(
	rasterizer->screen->width * rasterizer->screen->height*4);
	return rasterizer;
}
