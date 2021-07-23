#pragma once

#include "DebugOpenGL.h"

#include "Shader.h"

//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>

namespace AaronEngine {
	class ShaderProgram {
	private:
		unsigned int id;

	public:
		ShaderProgram();
		~ShaderProgram();

		void Bind();
		void Unbind();
		void AttachShaders(Shader& vertexShader, Shader& fragmentShader);
		unsigned int GetID();
	};
}