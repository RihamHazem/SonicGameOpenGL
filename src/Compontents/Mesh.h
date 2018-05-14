#pragma once
// Std. Includes
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// GL Includes
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Other Includes
#include "Shader.h"
#include "Texture.h"


struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

class Mesh {
private:
	GLuint VAO, VBO, EBO;

public:
	/*  Mesh Data  */
	GLfloat Shininess;
	vector<Vertex> Vertices;
	vector<GLuint> Indices;
	vector<Texture> Textures;

	/* Constructs a mesh from vertices data */
	Mesh(const vector<Vertex>& vertices, const vector<GLuint>& indices, const vector<Texture>& textures);

	/* Destructs the mesh */
	~Mesh();

	/* Render the mesh */
	void Draw(const Shader& shader);

private:
	/* Initializes all the buffer objects and arrays from mesh's data */
	void SetupMesh();
};