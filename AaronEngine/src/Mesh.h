#pragma once

#include "DebugOpenGL.h"

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

using namespace std;

namespace AaronEngine {
    struct Vertex {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
        glm::vec3 Tangent;
        glm::vec3 Bitangent;
    };

    struct Texture {
        unsigned int id;
        string type;
        string path;
    };

    struct Mesh {
        vector<Vertex> vertices;
        vector<unsigned int> indices;
        vector<Texture> textures;

        Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures) {
            this->vertices = vertices;
            this->indices = indices;
            this->textures = textures;
        }
    };
}