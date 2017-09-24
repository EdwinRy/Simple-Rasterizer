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

Vec2d * createVec2d(float x, float y)
{
	Vec2d * vec2 = malloc(sizeof(Vec2d));
	vec2->x = x;
	vec2->y = y;
	return vec2;
}

Vec3d * createVec3d(float x, float y, float z)
{
	Vec3d * vec3 = malloc(sizeof(Vec3d));
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
	return vec3;
}



void convertCoordToVec3d(Rasterizer* renderer, Vec3d* coord)
{
	coord->x = (0.5 * renderer->screen->width)
				- (-coord->x * 0.5 * (renderer->screen->width));
	coord->y = (0.5 * renderer->screen->height)
				 - (coord->y * 0.5 * (renderer->screen->height));
	coord->z;
}

void convertCoordToVec2d(Rasterizer* renderer, Vec2d* coord)
{
	coord->x *= renderer->screen->width;
	coord->y *= renderer->screen->height;
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

float min(float x, float y, float z)
{
	float minimum = x;
	if(y < minimum){minimum = y;}
	if(z < minimum){minimum = z;}
	return minimum;
}

float max(float x, float y, float z)
{
	float maximum = x;
	if(y > maximum){maximum = y;}
	if(z > maximum){maximum = z;}
	return maximum;
}

int testEdge(Vec3d * v0, Vec3d * v1, Vec3d * v2)
{
	return (int)((v1->x - v0->x) * (v2->y - v0->y) -
		(v1->y - v0->y) * (v2->x - v0->x));
}

void drawTriangle(Rasterizer* renderer,Vec3d * v0, Vec3d * v1, Vec3d * v2)
{
	//calculate bounding rectangle
	int minx = (int)min(v0->x, v1->x, v2->x);
	int maxx = (int)max(v0->x, v1->x, v2->x);
	int miny = (int)min(v0->y, v1->y, v2->y);
	int maxy = (int)max(v0->y, v1->y, v2->y);
	
	Vec3d* point = createVec3d(0,0,0);
	for(int y = miny; y < maxy; y++)
	{
		for(int x = minx; x < maxx; x++)
		{
			point->x = x;
			point->y = y;
			int e1 = testEdge(v0,v1,point);
			int e2 = testEdge(v1,v2,point);
			int e3 = testEdge(v2,v0,point);	
			
			if(e1 < 0 && e2 < 0 && e3 < 0 )
			{
				setPixel(renderer, x, y, 255, 255, 255, 255);
			}
		}
	}
}
