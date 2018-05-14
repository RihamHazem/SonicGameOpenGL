#include "Model.h"

/* Constructs a model from the specified file */
Model::Model(const char* path) {
	this->LoadModel(path);
}

/* Destructs the model and free resources up */
Model::~Model() {

}

/* Draws the model, and thus all its meshes */
void Model::Draw(const Shader& shader) {
	for (int i = 0; i < this->mMeshes.size(); ++i) {
		this->mMeshes[i].Draw(shader);
	}
}

/* Loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector */
void Model::LoadModel(const string& path) {
	// Read file via ASSIMP
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	// Check for errors
	if (scene == NULL || scene->mRootNode == NULL || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE) {
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}

	// Retrieve the directory path of the filepath
	this->mDirectory = path.substr(0, path.find_last_of('/'));

	// Process ASSIMP's root node recursively
	this->ProcessNode(scene->mRootNode, scene);
}

/* Processes nodes recursively and retrieve their data */
void Model::ProcessNode(const aiNode* node, const aiScene* scene) {
	// Process each mesh located at the current node
	for (int i = 0; i < node->mNumMeshes; ++i) {
		// The node object only contains indices to index the actual objects in the scene. 
		// The scene contains all the data, node is just to keep stuff organized (like relations between nodes).
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		this->mMeshes.push_back(this->ProcessMesh(mesh, scene));
	}

	// After we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (int i = 0; i < node->mNumChildren; ++i) {
		this->ProcessNode(node->mChildren[i], scene);
	}
}

/* Processes a mesh and retrieve its data */
Mesh Model::ProcessMesh(const aiMesh* mesh, const aiScene* scene) {
	// Mesh data to fill
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

	// Loop through each of the mesh's vertices
	for (int i = 0; i < mesh->mNumVertices; ++i) {
		Vertex vertex;
		glm::vec3 vector;

		// Position
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;
		// Normal
		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		vertex.Normal = vector;

		// Texture Coordinates
		if (mesh->mTextureCoords[0] != NULL) {
			glm::vec2 vec;
			// A vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
			// use models where a vertex can have multiple texture coordinates so we always take the first set (0).
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else {
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}
		
		vertices.push_back(vertex);
	}

	// Loop through each of the mesh's faces and retrieve the corresponding vertex indices.
	for (int i = 0; i < mesh->mNumFaces; ++i) {
		const aiFace& face = mesh->mFaces[i];

		// Retrieve all indices of the face and store them in the indices vector
		for (int j = 0; j < face.mNumIndices; ++j) {
			indices.push_back(face.mIndices[j]);
		}
	}

	// Process materials
	if (mesh->mMaterialIndex >= 0) {
		const aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		// We assume a convention for sampler names in the shaders. Each diffuse texture should be named
		// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
		// Same applies to other texture as the following list summarizes:
		// Diffuse:		texture_diffuseN
		// Specular:	texture_specularN
		// Normal:		texture_normalN

		// 1. Diffuse maps
		this->LoadMaterialTextures(material, aiTextureType_DIFFUSE, "material.diffuse", textures);
		// 2. Specular maps
		this->LoadMaterialTextures(material, aiTextureType_SPECULAR, "material.specular", textures);
	}

	// Return a mesh object created from the extracted mesh data
	return Mesh(vertices, indices, textures);
}

/* Returns all material textures of a given type */
void Model::LoadMaterialTextures(const aiMaterial* material, aiTextureType type, const char* texture_type, vector<Texture>& textures_list) {
	int TexturesCount = material->GetTextureCount(type);

	// Loop through each of the material's texture s
	for (int i = 0; i < TexturesCount; ++i) {
		aiString str;
		material->GetTexture(type, i, &str);

		// Check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
		map<string, Texture>::iterator it = this->mLoadedTextures.find(str.C_Str());

		if (it == this->mLoadedTextures.end()) {
			// Texture needs to be loaded for the first time
			string path = this->mDirectory + "/" + str.C_Str();
			Texture texture(path.c_str(), texture_type);
			textures_list.push_back(texture);
			this->mLoadedTextures[str.C_Str()] = texture;  // Store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
		}
		else {
			// Texture was loaded before
			textures_list.push_back(it->second);
		}
	}
}
