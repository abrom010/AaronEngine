#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "DebugOpenGL.h"

#include <iostream>

#include "Window.h"
#include "VertexArrayObject.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"
#include "Model.h"


namespace AaronEngine {
	class Renderer
	{
	private:
		Window window;
	public:
		Renderer(Window& window);
		~Renderer();

		void SetBackgroundColor(float r, float g, float b, float a);
		void Clear();
		void Update();
		void DrawTriangle();
		void DrawModel(Model model);
		
		std::string basicVertexShader =
			"#version 330 core\n"
			"layout(location = 0) in vec3 position;\n"

			"void main()\n"
			"{\n"
			"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
			"}\n";

		std::string basicFragmentShader =
			"#version 330 core\n"
			"out vec4 FragColor;\n"

			"void main()\n"
			"{\n"
				"FragColor = vec4(1.0f, 0.5f, 1.0f, 1.0f);\n"
			"}\n";
	};
}