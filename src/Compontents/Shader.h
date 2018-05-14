#pragma once
// Std. Includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// GL Includes
#include <GL/glew.h>


class Shader
{
public:
	GLuint ProgramID;

	/* Compiles and links the vertex and fragment shaders into a program */
	Shader(const char* vertex_path, const char* fragment_path);

	/* Destructs the compiled program when it is out of scope */
	~Shader();

	/* Activates the current shader */
	void Use();
};