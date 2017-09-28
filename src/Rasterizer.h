#include <stdio.h>
#include <stdlib.h>
#ifndef RASTERIZER_H
#define RASTERIZER_H

//Define structures
typedef struct Vec2f
{
	float x,y;
}Vec2f;

typedef struct Vec3f
{
	float x,y,z;
}Vec3f;

typedef struct Mat4
{
	float * val;
}Mat4;

//Screen structure through which the rasterizer accesses pixels
typedef struct Screen
{
    int width,height;
	char * pixels;
}Screen;

typedef struct Object
{
	Vec3f ** verts;
	int vertCount;
	int * indices;
	int indicesCount;
	vec2f * textureCoords;
	int textureCoordCount;
	Mat4 * transformationMatrix;	
}Object;

typedef struct Rasterizer
{
	Screen* screen;
	char * depthBuffer;
	Object ** objs;
	int objCount;
	float far;
	float near;
	float fov;
	Mat4 * projectionMatrix;
}Rasterizer;

//Renderer Initialisation
Screen* createScreen(int width, int height);
Rasterizer* createRasterizer(Screen* screen);
Object* createObject(Vec3f *verts, int vertC, int * indices, int indicesC);
void loadObject(Rasterizer* renderer, Object* obj);

//pre-rendering funtions
Vec2f * createVec2f(float x, float y);
Vec3f * createVec3f(float x, float y, float z);

Mat4 * createMat4();
void applyPerspective(Rasterizer* renderer, float near, float far, float fov);
void applyProjection(Rasterizer* renderer, Mat4* projection);
void convertCoordToVec3f(Rasterizer * renderer, Vec3f* coord);
void convertCoordToVec2f(Rasterizer * renderer, Vec2f* coord);

void loadCoords(Object* obj, Vec3f ** coords, int count);
void loadIndices(Object* obj, int * indices, int count);

//Rendering function
void setPixel(Rasterizer* rasterizer,
int x, int y, char r, char g, char b, char a);
void translate(Object* obj, Vec3f * x, Vec3f * y, Vec3f * z);
void rotate(Object* obj,Vec3f * x, Vec3f * y, Vec3f * z);	
void drawTriangle(Rasterizer * renderer, Vec3f * v0, Vec3f * v1, Vec3f * v2);
void drawTriangles(Rasterizer * renderer);
void drawIndices(Rasterizer * renderer);
void renderObject(Rasterizer * renderer, Object* obj);
#endif
