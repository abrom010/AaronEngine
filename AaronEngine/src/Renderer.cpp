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

	//void Renderer::DrawModel(Model model)
	//{
	//	for (unsigned int i = 0; i < model.meshes.size(); i++)
	//		this->DrawMesh(model.meshes[i]);
	//}

	//void Renderer::DrawMesh(Mesh mesh)
	//{
	//	unsigned int diffuseNr = 1;
	//	unsigned int specularNr = 1;
	//	unsigned int normalNr = 1;
	//	unsigned int heightNr = 1;
	//	for (unsigned int i = 0; i < mesh.textures.size(); i++)
	//	{
	//		glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
	//		// retrieve texture number (the N in diffuse_textureN)
	//		std::string number;
	//		std::string name = mesh.textures[i].type;
	//		if (name == "texture_diffuse")
	//			number = std::to_string(diffuseNr++);
	//		else if (name == "texture_specular")
	//			number = std::to_string(specularNr++); // transfer unsigned int to stream
	//		else if (name == "texture_normal")
	//			number = std::to_string(normalNr++); // transfer unsigned int to stream
	//		else if (name == "texture_height")
	//			number = std::to_string(heightNr++); // transfer unsigned int to stream

	//		AaronEngine::Shader vertexShader(AaronEngine::Shader::ShaderType::VERTEX);
	//		vertexShader.AttachSourceFromString(this->basicVertexShader);
	//		vertexShader.Compile();
	//		AaronEngine::Shader fragmentShader(AaronEngine::Shader::ShaderType::FRAGMENT);
	//		fragmentShader.AttachSourceFromString(this->basicFragmentShader);
	//		fragmentShader.Compile();

	//		AaronEngine::ShaderProgram shaderProgram;
	//		shaderProgram.AttachShaders(vertexShader, fragmentShader);
	//		shaderProgram.Bind();

	//		// now set the sampler to the correct texture unit
	//		glUniform1i(glGetUniformLocation(shaderProgram.GetID(), (name + number).c_str()), i);
	//		// and finally bind the texture
	//		glBindTexture(GL_TEXTURE_2D, mesh.textures[i].id);
	//	}

	//	// draw mesh
	//	glBindVertexArray(mesh.VAO);
	//	glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);
	//	glBindVertexArray(0);

	//	// always good practice to set everything back to defaults once configured.
	//	glActiveTexture(GL_TEXTURE0);
	//}

}