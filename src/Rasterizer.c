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

Vec2f * createVec2f(float x, float y)
{
	Vec2f * vec2 = malloc(sizeof(Vec2f));
	vec2->x = x;
	vec2->y = y;
	return vec2;
}

Vec3f * createVec3f(float x, float y, float z)
{
	Vec3f * vec3 = malloc(sizeof(Vec3f));
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
	return vec3;
}


void convertCoordToVec3f(Rasterizer* renderer, Vec3f* coord)
{
	coord->x = (0.5 * renderer->screen->width)
				- (-coord->x * 0.5 * (renderer->screen->width));
	coord->y = (0.5 * renderer->screen->height)
				 - (coord->y * 0.5 * (renderer->screen->height));
}

void convertCoordToVec2f(Rasterizer* renderer,Vec2f * coord)
{
	coord->x = (0.5 * renderer->screen->width)
				- (-coord->x * 0.5 * (renderer->screen->width));
	coord->y = (0.5 * renderer->screen->height)
				 - (coord->y * 0.5 * (renderer->screen->height));
}

void loadCoords(Rasterizer * renderer, Vec3f ** coords, int count)
{
	for(int i = 0; i < count; i++)
	{
		convertCoordToVec3f(renderer,coords[i]);
	}

	renderer->verts = coords;
	renderer->vertCount = count;

	
}

void loadIndices(Rasterizer* renderer,int * indices, int count)
{
	renderer->indices = indices;
	renderer->indicesCount = count;
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

void drawTriangle(Rasterizer* renderer,Vec3f * v0, Vec3f * v1, Vec3f * v2)
{
	//calculate bounding rectangle
	int minx = (int)min(v0->x, v1->x, v2->x);
	int maxx = (int)max (v0->x, v1->x, v2->x);
	int miny = (int)min(v0->y, v1->y, v2->y);
	int maxy = (int)max(v0->y, v1->y, v2->y);

	float C1X = v1->x - v0->x;
	float C2X = v2->x - v1->x;
	float C3X = v0->x - v2->x;

	float C1Y = v1->y - v0->y;
	float C2Y = v2->y - v1->y;
	float C3Y = v0->y - v2->y;

	float CY1;
	float CY2;
	float CY3;

	float CX1;
	float CX2;
	float CX3;
	
	float area = C1X*(v2->y - v0->y)-C1Y*(v2->x-v0->x);

	for(int y = miny; y < maxy; y++)
	{
		CY1 = C1X * (y - v0->y);
		CY2 = C2X * (y - v1->y);
		CY3 = C3X * (y - v2->y);
	
		for(int x = minx; x < maxx; x++)
		{
			CX1 = C1Y * (x - v0->x);
			CX2 = C2Y * (x - v1->x);
			CX3 = C3Y * (x - v2->x);
			
			if(CY1 <=  CX1 && CY2 <= CX2 && CY3 <= CX3 )
			{
				setPixel(renderer, x, y, 255, 255, 255, 255);
			}
		}
	}
}

#ifdef WIN32
	//include windows multi-threading
#else
void drawTriangles(Rasterizer * renderer)
{
	for(int i = 0; i < renderer->vertCount; i+=3)
	{
		drawTriangle(
					renderer, 
					renderer->verts[0+i],
					renderer->verts[1+i],
					renderer->verts[2+i]
					);
	}	
}

void drawIndices(Rasterizer * renderer)
{
	for(int i = 0; i < renderer->indicesCount; i+=3)
	{
		drawTriangle(
					renderer,
					renderer->verts[(int)renderer->indices[0+i]],
					renderer->verts[(int)renderer->indices[1+i]],
					renderer->verts[(int)renderer->indices[2+i]]
					);
	}

}
#endif
