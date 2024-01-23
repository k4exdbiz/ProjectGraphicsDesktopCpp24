#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

typedef unsigned int TextureID;

struct Texture
{
	int id;
	int width;
	int height;
};

Texture loadTexture(const char* filepath);



#endif