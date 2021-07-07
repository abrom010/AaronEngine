#pragma once

#include "DebugOpenGL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>

//#include "Mesh.h"

namespace AaronEngine {
	class Model
	{
	private:
		bool gammaCorrection;
	public:
		Model(std::string filePath, bool gammaCorrection);
	};
}