#include "ShaderProgram.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace AaronEngine {
	ShaderProgram::ShaderProgram()
	{
		this->id = glCreateProgram();
		this->Unbind();
	}

	ShaderProgram::~ShaderProgram(){}

	void ShaderProgram::Bind()
	{
		glUseProgram(this->id);
	}

	void ShaderProgram::Unbind()
	{
		glUseProgram(0);
	}

	void ShaderProgram::AttachShaders(unsigned int vertexShaderID, unsigned int fragmentShaderID)
	{
		this->Bind();
		glAttachShader(this->id, vertexShaderID);
		glAttachShader(this->id, fragmentShaderID);
		glLinkProgram(this->id);
		
		int success;
		char infoLog[512];
		glGetProgramiv(this->id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(this->id, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		this->Unbind();
	}
}