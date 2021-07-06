#include "Renderer.h"

namespace AaronEngine {
	Renderer::Renderer(Window& window)
		: window(window)
	{
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GLCall(glEnable(GL_DEPTH_TEST));
	}

	Renderer::~Renderer()
	{

	}

	void Renderer::SetBackgroundColor(float r, float g, float b, float a)
	{
		GLCall(glClearColor(r, g, b, a));
	}

	void Renderer::Clear()
	{
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void Renderer::Update()
	{
		glfwSwapBuffers(this->window.GetWindow());
		glfwPollEvents();
	}

	void Renderer::DrawTriangle()
	{
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2
		};

		AaronEngine::Shader vertexShader(AaronEngine::Shader::ShaderType::VERTEX);
		vertexShader.AttachSourceFromString(this->basicVertexShader);
		vertexShader.Compile();
		AaronEngine::Shader fragmentShader(AaronEngine::Shader::ShaderType::FRAGMENT);
		fragmentShader.AttachSourceFromString(this->basicFragmentShader);
		fragmentShader.Compile();

		AaronEngine::ShaderProgram shaderProgram;
		shaderProgram.AttachShaders(vertexShader, fragmentShader);
		shaderProgram.Bind();

		AaronEngine::VertexArrayObject vao;
		vao.Bind();

		AaronEngine::VertexBufferObject vbo;
		vbo.Bind();
		vbo.AttachData(vertices, 3 * 3 * sizeof(float));

		AaronEngine::IndexBufferObject ibo;
		ibo.Bind();
		ibo.AttachData(indices, 3);

		AaronEngine::VertexBufferLayout vbl;
		vbl.AddAttribute<float>(3);

		vao.AttachVertexBufferObject(vbo, vbl);

		GLCall(glDrawElements(GL_TRIANGLES, ibo.GetIndexCount(), GL_UNSIGNED_INT, nullptr));
	}

	void Renderer::DrawModel(Model model)
	{

	}

}