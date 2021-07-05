#include "Window.h"
#include "Renderer.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"
#include "Shader.h"

int main()
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	float indices[] = {
		0, 1, 2
	};

	AaronEngine::Window window(1280, 720, "Sandbox");
	AaronEngine::Renderer renderer;

	AaronEngine::VertexArrayObject vao;
	
	AaronEngine::VertexBufferObject vbo;
	vbo.AttachData(vertices, 3 * 3);

	AaronEngine::VertexBufferLayout vbl;
	vbl.AddAttribute<float>(3);

	vao.AttachVertexBufferObject(vbo, vbl);

	AaronEngine::IndexBufferObject ibo;

	AaronEngine::ShaderProgram shaderProgram;
	
	AaronEngine::Shader vertexShader(AaronEngine::Shader::ShaderType::VERTEX);
	vertexShader.AttachSourceFromString(renderer.basicVertexShader);
	vertexShader.Compile();
	AaronEngine::Shader fragmentShader(AaronEngine::Shader::ShaderType::FRAGMENT);
	fragmentShader.AttachSourceFromString(renderer.basicFragmentShader);
	fragmentShader.Compile();

	shaderProgram.AttachShaders(vertexShader.getID(), fragmentShader.getID());	

	while (!window.shouldClose())
	{
		renderer.Clear();
		renderer.Draw(vao, ibo, shaderProgram);
		renderer.Update(window);
	}
}