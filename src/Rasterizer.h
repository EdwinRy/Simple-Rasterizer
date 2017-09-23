#include <stdio.h>
#include <stdlib.h>
#ifndef RASTERIZER_H
#define RASTERIZER_H

//Define Vector structures
typedef struct Vec2d
{
	float x,y;
}Vec2d;

typedef struct Vec3d
{

	float x,y,z;
}Vec3d;

//Screen structure through which the rasterizer accesses pixels
typedef struct Screen
{
    int width,height;
	char * pixels;
}Screen;

typedef struct Rasterizer
{
	Screen* screen;
	char * depthBuffer;
	Vec3d * vectors;
}Rasterizer;

//Renderer Initialisation
Screen* createScreen(int width, int height);
Rasterizer* createRasterizer(Screen* screen);

//Rendering funtions
void setPixel(Rasterizer* rasterizer,
float x, float y, char r, char g, char b, char a);
void DrawTriangle(Vec3d * v0, Vec3d * v1, Vec3d * v2);
#endif
