#pragma once

#include "DebugOpenGL.h"

#include <iostream>

#include "Window.h"
#include "VertexArrayObject.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "Mesh.h"
#include "Sprite.h"

namespace AaronEngine {
	class Renderer {
	private:
		Window window;
	public:
		Renderer(Window& window);
		~Renderer();

		void SetBackgroundColor(float r, float g, float b, float a);
		void Clear();
		void Update();
		void DrawTriangle();
		void DrawModel(Model& model);
		void DrawMesh(Mesh& mesh, glm::mat4 transform);
		void DrawSprite(Sprite& sprite);
		
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

		std::string modelVertexShader =
			"#version 330 core\n"
			"layout(location = 0) in vec3 aPos;\n"
			"layout(location = 1) in vec3 aNormal;\n"
			"layout(location = 2) in vec2 aTexCoords;\n"

			"out vec2 TexCoords;\n"

			"uniform mat4 model;\n"
			"uniform mat4 view;\n"
			"uniform mat4 projection;\n"

			"void main()\n"
			"{\n"
			"TexCoords = aTexCoords;\n"
			"gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
			"}\n";

		std::string modelFragmentShader =
			"#version 330 core\n"
			"out vec4 FragColor;\n"

			"in vec2 TexCoords;\n"

			"uniform sampler2D texture_diffuse1;\n"

			"void main()\n"
			"{\n"
			"FragColor = texture(texture_diffuse1, TexCoords);\n"
			"}\n";

		std::string spriteVertexShader =
			"#version 330 core\n"
			"layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>\n"

			"out vec2 TexCoords;\n"

			"uniform mat4 model;\n"
			"uniform mat4 projection;\n"

			"void main()\n"
			"{\n"
			"TexCoords = vertex.zw;\n"
			"gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);\n"
			"}\n";

		std::string spriteFragmentShader =
			"#version 330 core\n"
			"in vec2 TexCoords;\n"
			"out vec4 color;\n"

			"uniform sampler2D image;\n"

			"void main()\n"
			"{\n"
			"color = vec4(1.0, 1.0, 1.0, 1.0) * texture(image, TexCoords); \n"
			"}\n";
	};
}