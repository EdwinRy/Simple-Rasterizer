#include <stdio.h>
#ifndef RASTERIZER_H
#define RASTERIZER_H
typedef struct Screen
{
    int width,height;
	char * pixels;
}Screen;

typedef struct Rasterizer
{
	Screen* screen;
}Rasterizer;

void setPixel(Rasterizer* rasterizer,
float x, float y, char r, char g, char b);

Screen* createScreen(char* title, int width, int height);
Rasterizer* createRasterizer(Screen* screen);
void DrawTriangle();

#endif
