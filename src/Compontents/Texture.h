#pragma once
// Std. Includes
#include <string>
using namespace std;

// GL Includes
#include <GL/glew.h>

// Image Loading Library Includes
#include <SOIL/SOIL.h>


class Texture
{
public:
	GLuint ID;
	string Type;

	Texture() {}
	
	/* Loads texture from a file */
	Texture(const char* path, const char* type);

	/* Destructs the texture and free resources up */
	~Texture();
};