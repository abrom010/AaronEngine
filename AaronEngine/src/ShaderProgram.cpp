#include "ShaderProgram.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace AaronEngine {
	ShaderProgram::ShaderProgram()
	{
		GLCall(this->id = glCreateProgram());
	}

	ShaderProgram::~ShaderProgram(){}

	void ShaderProgram::Bind()
	{
		GLCall(glUseProgram(this->id));
	}

	void ShaderProgram::Unbind()
	{
		GLCall(glUseProgram(0));
	}

	void ShaderProgram::AttachShaders(Shader& vertexShader, Shader& fragmentShader)
	{
		GLCall(glAttachShader(this->id, vertexShader.GetID()));
		GLCall(glAttachShader(this->id, fragmentShader.GetID()));
		GLCall(glLinkProgram(this->id));
		
		int success;
		char infoLog[512];
		GLCall(glGetProgramiv(this->id, GL_LINK_STATUS, &success));
		if (!success)
		{
			GLCall(glGetProgramInfoLog(this->id, 512, NULL, infoLog));
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		GLCall(glDeleteShader(vertexShader.GetID()));
		GLCall(glDeleteShader(fragmentShader.GetID()));
	}

	unsigned int ShaderProgram::GetID()
	{
		return this->id;
	}
}