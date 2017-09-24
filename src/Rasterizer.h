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

//pre-rendering funtions
Vec2d * createVec2d(float x, float y);
Vec3d * createVec3d(float x, float y, float z);

void convertCoordToVec3d(Rasterizer * renderer, Vec3d* coord);
void convertCoordToVec2d(Rasterizer * renderer, Vec2d* coord);

void loadCoordToRenderer(Rasterizer * renderer, Vec3d * vec);

//Rendering function
void setPixel(Rasterizer* rasterizer,
int x, int y, char r, char g, char b, char a);
void drawTriangle(Rasterizer * renderer, Vec3d * v0, Vec3d * v1, Vec3d * v2);
#endif
