#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "DebugOpenGL.h"

#include "Shader.h"

namespace AaronEngine {
	class ShaderProgram
	{
	private:
		unsigned int id;

	public:
		ShaderProgram();
		~ShaderProgram();

		void Bind();
		void Unbind();
		void AttachShaders(Shader& vertexShader, Shader& fragmentShader);
	};
}