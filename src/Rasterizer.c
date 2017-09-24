#include "Rasterizer.h"
Screen* createScreen(int width, int height)
{
	Screen* screen = malloc(sizeof(Screen));
	screen->width = width;
	screen->height = height;
	screen->pixels = calloc(width*height*4,1);	
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

Vec2d * createVec2d(int x, int y)
{
	Vec2d * vec2 = malloc(sizeof(Vec2d));
	vec2->x = x;
	vec2->y = y;
	return vec2;
}

Vec3d * createVec3d(int x, int y, int z)
{
	Vec3d * vec3 = malloc(sizeof(Vec3d));
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
	return vec3;
}



Vec3d * convertCoordToVec3d(Vec3d* coord)
{

}

Vec2d * convertCoordToVec2d(Vec2d* coord)
{

}



void setPixel(Rasterizer* rasterizer,
int x, int y, char r, char g, char b, char a)
{	
	x = (x * 4) + (y * (500*4));
	rasterizer->screen->pixels[x] = b;
	rasterizer->screen->pixels[x + 1] = g;
	rasterizer->screen->pixels[x + 2] = r;
	rasterizer->screen->pixels[x + 3] = a;
}

void drawTriangle(Vec3d * v0, Vec3d * v1, Vec3d * v2)
{
	
}
