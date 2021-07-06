#pragma once

#include "DebugOpenGL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

#include <vector>

namespace AaronEngine {
	class Model
	{
	private:
		

	public:
		std::vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
		std::vector<Mesh> meshes;
		std::string directory;
		bool gammaCorrection;

		Model(std::string const& path, bool gamma);
		~Model();

		void LoadModel(std::string filePath);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

		std::vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	};
}