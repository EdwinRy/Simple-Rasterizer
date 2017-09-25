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
}

void convertCoordToVec2d(Rasterizer* renderer, Vec2d* coord)
{
	coord->x *= renderer->screen->width;
	coord->y *= renderer->screen->height;
}

void setPixel(Rasterizer* rasterizer,
int x, int y, char r, char g, char b, char a)
{	
	if(x<rasterizer->screen->width)
	{	
		x = (x * 4) + (y * (rasterizer->screen->width*4));
		rasterizer->screen->pixels[x] = b;
		rasterizer->screen->pixels[x + 1] = g;
		rasterizer->screen->pixels[x + 2] = r;
		rasterizer->screen->pixels[x + 3] = a;
	}
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

void drawTriangle(Rasterizer* renderer,Vec3d * v0, Vec3d * v1, Vec3d * v2)
{
	//calculate bounding rectangle
	int minx = (int)min(v0->x, v1->x, v2->x);
	int maxx = (int)max(v0->x, v1->x, v2->x);
	int miny = (int)min(v0->y, v1->y, v2->y);
	int maxy = (int)max(v0->y, v1->y, v2->y);

	float C1X = v1->x - v0->x;
	float C2X = v2->x - v1->x;
	float C3X = v0->x - v2->x;

	float C1Y = v1->y - v0->y;
	float C2Y = v2->y - v1->y;
	float C3Y = v0->y - v2->y;
	
	for(int y = miny; y < maxy; y++)
	{
		float CY1 = C1X * (y - v0->y);
		float CY2 = C2X * (y - v1->y);
		float CY3 = C3X * (y - v2->y);
	
		for(int x = minx; x < maxx; x++)
		{
			float CX1 = C1Y * (x - v0->x);
			float CX2 = C2Y * (x - v1->x);
			float CX3 = C3Y * (x - v2->x);
						
			//int e1 = CY1 - CX1;
			//int e2 = CY2 - CX2;
			//int e3 = CY3 - CX3;

			if(CY1 - CX1 < 0 && CY2 - CX2 < 0 && CY3 - CX3 < 0 )
			{
				setPixel(renderer, x, y, 255, 255, 255, 255);
			}
		}
	}
}
