#include "Renderer.h"

namespace AaronEngine {
	Renderer::Renderer(Window& window) : window(window) {
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GLCall(glEnable(GL_DEPTH_TEST));
	}

	Renderer::~Renderer() {

	}

	void Renderer::SetBackgroundColor(float r, float g, float b, float a) {
		GLCall(glClearColor(r, g, b, a));
	}

	void Renderer::Clear() {
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void Renderer::Update() {
		glfwSwapBuffers(this->window.GetWindow());
		glfwPollEvents();
	}

	void Renderer::DrawTriangle() {
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

	void Renderer::DrawModel(Model& model) {
		for (unsigned int i = 0; i < model.meshes.size(); i++)
			this->DrawMesh(model.meshes[i], model.transform);
	}

	void Renderer::DrawMesh(Mesh& mesh, glm::mat4 transform) {
		unsigned int diffuseNr = 1;
		unsigned int specularNr = 1;
		unsigned int normalNr = 1;
		unsigned int heightNr = 1;

		AaronEngine::Shader vertexShader(AaronEngine::Shader::ShaderType::VERTEX);
		vertexShader.AttachSourceFromString(this->modelVertexShader);
		vertexShader.Compile();
		AaronEngine::Shader fragmentShader(AaronEngine::Shader::ShaderType::FRAGMENT);
		fragmentShader.AttachSourceFromString(this->modelFragmentShader);
		fragmentShader.Compile();

		AaronEngine::ShaderProgram shaderProgram;
		shaderProgram.AttachShaders(vertexShader, fragmentShader);
		shaderProgram.Bind();

		int modelUniform = glGetUniformLocation(shaderProgram.GetID(), "model");
		int viewUniform = glGetUniformLocation(shaderProgram.GetID(), "view");
		int projectionUniform = glGetUniformLocation(shaderProgram.GetID(), "projection");
		glm::mat4 model = transform;

		glm::mat4 view = glm::mat4(1.0);
		view = glm::translate(view, glm::vec3(0, 0, -5));
		view = glm::rotate(view, 2 * 1.5708f, glm::vec3(0, 0, 1));

		glm::mat4 projection = glm::perspective(30.0f, (GLfloat)window.GetWidth() / (GLfloat)window.GetHeight(), 1.0f, 100.0f);

		GLCall(glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &model[0][0]));
		GLCall(glUniformMatrix4fv(viewUniform, 1, GL_FALSE, &view[0][0]));
		GLCall(glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, &projection[0][0]));

		unsigned int VAO, VBO, EBO;
		
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(Mesh::Vertex), &mesh.vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), &mesh.indices[0], GL_STATIC_DRAW);

		
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)0);
		
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)offsetof(Mesh::Vertex, Normal));
		
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)offsetof(Mesh::Vertex, TexCoords));
		
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)offsetof(Mesh::Vertex, Tangent));
		
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Mesh::Vertex), (void*)offsetof(Mesh::Vertex, Bitangent));

		glBindVertexArray(0);

		for (unsigned int i = 0; i < mesh.textures.size(); i++) {
			glActiveTexture(GL_TEXTURE0 + i);
			std::string number;
			std::string name = mesh.textures[i].type;
			if (name == "texture_diffuse")
				number = std::to_string(diffuseNr++);
			else if (name == "texture_specular")
				number = std::to_string(specularNr++);
			else if (name == "texture_normal")
				number = std::to_string(normalNr++);
			else if (name == "texture_height")
				number = std::to_string(heightNr++);

			glUniform1i(glGetUniformLocation(shaderProgram.GetID(), (name + number).c_str()), i);
			glBindTexture(GL_TEXTURE_2D, mesh.textures[i].id);
		}

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glActiveTexture(GL_TEXTURE0);
	}

	void Renderer::DrawSprite(Sprite& sprite) {

	}
}