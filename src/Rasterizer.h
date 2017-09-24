#include <stdio.h>
#include <stdlib.h>
#ifndef RASTERIZER_H
#define RASTERIZER_H

//Define Vector structures
typedef struct Vec2d
{
	int x,y;
}Vec2d;

typedef struct Vec3d
{

	int x,y,z;
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
Vec2d * createVec2d(int x, int y);
Vec3d * createVec3d(int x, int y, int z);

Vec3d* convertCoordToVec3d(Vec3d* coord);
Vec2d* convertCoordToVec2d(Vec2d* coord);

void loadCoordToRenderer(Rasterizer * renderer, Vec3d * vec);

//Rendering function
void setPixel(Rasterizer* rasterizer,
int x, int y, char r, char g, char b, char a);
void DrawTriangle(Vec3d * v0, Vec3d * v1, Vec3d * v2);
#endif
