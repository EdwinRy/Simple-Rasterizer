#include <stdio.h>
#include <stdlib.h>
#ifndef RASTERIZER_H
#define RASTERIZER_H

typedef struct Vec2d
{
	float x,y;
}Vec2d;

typedef struct Vec3d
{

	float x,y,z;
}Vec3d;

typedef struct Screen
{
    int width,height;
	char * pixels;
}Screen;

typedef struct Rasterizer
{
	Screen* screen;
	char * depthBuffer;
}Rasterizer;

void setPixel(Rasterizer* rasterizer,
float x, float y, char r, char g, char b);

Screen* createScreen(int width, int height);
Rasterizer* createRasterizer(Screen* screen);
void DrawTriangle();

#endif
