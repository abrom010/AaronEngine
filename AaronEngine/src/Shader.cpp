#include "Shader.h"

#include <fstream>
#include <sstream>
#include <algorithm>

#include <direct.h>

namespace AaronEngine {
	Shader::Shader(ShaderType shaderType) : shaderType(shaderType) {
		GLuint type = NULL;
		switch (shaderType) {
			case ShaderType::VERTEX:
				type = GL_VERTEX_SHADER;
				break;
			case ShaderType::FRAGMENT:
				type = GL_FRAGMENT_SHADER;
				break;
		}

		GLCall(this->id = glCreateShader(type));
	}

	Shader::~Shader() {
		GLCall(glDeleteShader(this->id));
	}

	unsigned int Shader::GetID() {
		return this->id;
	}

	void Shader::AttachSourceFromFile(std::string filePath) {
		std::ifstream fileStream(filePath);
		std::stringstream stringStream;
		stringStream << fileStream.rdbuf();
		std::cout << stringStream.str() << std::endl;
		std::string string = stringStream.str();
		const char* src = string.c_str();
		GLCall(glShaderSource(id, 1, &src, nullptr));
	}

	void Shader::AttachSourceFromString(std::string source) {
		const char* src = source.c_str();
		GLCall(glShaderSource(id, 1, &src, nullptr));
	}

	void Shader::Compile() {
		GLCall(glCompileShader(this->id));
		int  success;
		char infoLog[512];
		GLCall(glGetShaderiv(this->id, GL_COMPILE_STATUS, &success));

		if (!success) {
			GLCall(glGetShaderInfoLog(this->id, 512, NULL, infoLog));
			std::string typeString;
			if (this->shaderType == ShaderType::VERTEX)
				typeString = "VERTEX";
			else if (this->shaderType == ShaderType::FRAGMENT)
				typeString = "FRAGMENT";

			std::cout << "ERROR::SHADER::" << typeString << "::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
}