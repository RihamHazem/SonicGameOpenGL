#include "Mesh.h"

/* Constructs a mesh from vertices data */
Mesh::Mesh(const vector<Vertex>& vertices, const vector<GLuint>& indices, const vector<Texture>& textures) {
	this->Vertices = vertices;
	this->Indices = indices;
	this->Textures = textures;

	this->Shininess = 32.0f; // Set a default value for shininess

	// Now that we have all the required data, set the vertex buffers and its attribute pointers.
	this->SetupMesh();
}

/* Destructs the mesh */
Mesh::~Mesh() {
	// Release mesh's data from the memory
	//glDeleteBuffers(1, &this->VBO);
	//glDeleteBuffers(1, &this->EBO);
	//glDeleteVertexArrays(1, &this->VAO);
}

/* Render the mesh */
void Mesh::Draw(const Shader& shader) {
	// Bind appropriate textures
	GLuint diffuseCount = 0;
	GLuint specularCount = 0;

	for (int i = 0; i < this->Textures.size(); ++i) {
		// Active proper texture unit before binding
		glActiveTexture(GL_TEXTURE0 + i);
		
		// Retrieve texture number (the N in diffuse_textureN)
		stringstream ss;
		string number;
		string name = this->Textures[i].Type;

		if (name == "material.diffuse")
			ss << ++diffuseCount;	// Transfer GLuint to stream
		else if (name == "material.specular")
			ss << ++specularCount;	// Transfer GLuint to stream

		number = ss.str();

		// Now set the sampler to the correct texture unit
		glUniform1i(glGetUniformLocation(shader.ProgramID, (name + number).c_str()), i);

		// And finally bind the texture
		glBindTexture(GL_TEXTURE_2D, this->Textures[i].ID);
	}

	// Also set each mesh's shininess property to a default value (if you want you could extend this to another mesh property and possibly change this value)
	glUniform1f(glGetUniformLocation(shader.ProgramID, "material.shininess"), this->Shininess);

	// Draw mesh
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, this->Indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// Always good practice to set everything back to defaults once configured.
	for (int i = 0; i < this->Textures.size(); ++i) {
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

/* Initializes all the buffer objects and arrays from mesh's data */
void Mesh::SetupMesh() {
	// Create buffers/arrays
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);

	// Bind the vertex array
	glBindVertexArray(this->VAO);

	// Load data into vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->Vertices.size() * sizeof(Vertex), &this->Vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices.size() * sizeof(GLuint), &this->Indices[0], GL_STATIC_DRAW);
	
	// Set the vertex attribute pointers
	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
	// Vertex Texture Coordinates
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

	// Unbind vertex array and buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Disable attributes
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}