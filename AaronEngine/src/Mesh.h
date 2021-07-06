#pragma once

#include "DebugOpenGL.h"

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

namespace AaronEngine {
    struct Vertex {
        // position
        glm::vec3 Position;
        // normal
        glm::vec3 Normal;
        // texCoords
        glm::vec2 TexCoords;
        // tangent
        glm::vec3 Tangent;
        // bitangent
        glm::vec3 Bitangent;
    };

    struct Texture {
        unsigned int id;
        std::string type;
        std::string path;
    };

	class Mesh
	{
	private:

	public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        unsigned int VAO;

		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
		~Mesh();

        void SetupMesh();
	};
}