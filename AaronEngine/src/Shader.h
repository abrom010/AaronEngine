#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "DebugOpenGL.h"

#include <iostream>
#include <string>

namespace AaronEngine {
	class Shader
	{
	public:
		static enum class ShaderType
		{
			VERTEX, FRAGMENT
		};

	private:
		unsigned int id;
		ShaderType shaderType;
		std::string source;

	public:
		
		Shader(ShaderType shaderType);
		~Shader();

		unsigned int getID();
		void AttachSourceFromFile(std::string filePath);
		void AttachSourceFromString(std::string source);
		void Compile();
		
	};
}
