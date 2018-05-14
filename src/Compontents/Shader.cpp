#include "Shader.h"

/* Compiles and links the vertex and fragment shaders into a program */
Shader::Shader(const char* vertex_path, const char* fragment_path) {
	// 1. Retrieve the vertex/fragment source code from filePath
	string vertexCode, fragmentCode;
	ifstream vShaderFile, fShaderFile;

	// ensures ifstream objects can throw exceptions:
	vShaderFile.exceptions(ifstream::badbit);
	fShaderFile.exceptions(ifstream::badbit);

	try {
		// Open files
		vShaderFile.open(vertex_path);
		fShaderFile.open(fragment_path);
		// Read file's buffer contents into streams
		stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// 2. Compile shaders
	GLuint vertexID, fragmentID;
	GLint success;
	GLchar infoLog[512];

	// Vertex Shader
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &vShaderCode, NULL);
	glCompileShader(vertexID);

	// Print compile errors if any
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Fragment Shader
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &fShaderCode, NULL);
	glCompileShader(fragmentID);

	// Print compile errors if any
	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Shader Program
	this->ProgramID = glCreateProgram();
	glAttachShader(this->ProgramID, vertexID);
	glAttachShader(this->ProgramID, fragmentID);
	glLinkProgram(this->ProgramID);

	// Print linking errors if any
	glGetProgramiv(this->ProgramID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->ProgramID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

/* Destructs the compiled program when it is out of scope */
Shader::~Shader() {
	glDeleteProgram(this->ProgramID);
}

/* Activates the current shader */
void Shader::Use() {
	glUseProgram(this->ProgramID);
}