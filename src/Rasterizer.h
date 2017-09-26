#include <stdio.h>
#include <stdlib.h>
#ifndef RASTERIZER_H
#define RASTERIZER_H

//Define Vector structures
typedef struct Vec2f
{
	float x,y;
}Vec2f;

typedef struct Vec3f
{
	float x,y,z;
}Vec3f;

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
	Vec3f ** verts;
	int vertCount;
	int * indices;
	int indicesCount;
	Vec2f *	textureCoords;
	int texCoordCount;
	float far;
	float near;
	float fov;
}Rasterizer;

//Renderer Initialisation
Screen* createScreen(int width, int height);
Rasterizer* createRasterizer(Screen* screen);

//pre-rendering funtions
Vec2f * createVec2f(float x, float y);
Vec3f * createVec3f(float x, float y, float z);

void convertCoordToVec3f(Rasterizer * renderer, Vec3f* coord);
void convertCoordToVec2f(Rasterizer * renderer, Vec2f* coord);

void loadCoords(Rasterizer * renderer, Vec3f ** coords, int count);
void loadIndices(Rasterizer * renderer, int * indices, int count);

//Rendering function
void setPixel(Rasterizer* rasterizer,
int x, int y, char r, char g, char b, char a);
void drawTriangle(Rasterizer * renderer, Vec3f * v0, Vec3f * v1, Vec3f * v2);
void drawTriangles(Rasterizer * renderer);
void drawIndices(Rasterizer * renderer);
#endif
