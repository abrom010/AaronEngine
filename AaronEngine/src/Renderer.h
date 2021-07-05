#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Window.h"
#include "VertexArrayObject.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"

namespace AaronEngine {
	class Renderer
	{
	private:
	public:
		Renderer();
		~Renderer();

		void SetBackgroundColor(float r, float g, float b, float a);
		void Clear();
		void Update(Window& window);
		void Draw(VertexArrayObject vao, IndexBufferObject ibo, ShaderProgram shaderProgram);
		
		std::string basicVertexShader =
			"#version 330 core\n"
			"layout(location = 0) in vec3 aPos;\n"

			"void main()\n"
			"{\n"
			"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\n";
		std::string basicFragmentShader =
			"#version 330 core\n"
			"out vec4 FragColor;\n"

			"void main()\n"
			"{\n"
			"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n";
	};
}