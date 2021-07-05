#pragma once

namespace AaronEngine {
	class ShaderProgram
	{
	private:
		unsigned int id;

	public:
		ShaderProgram();
		~ShaderProgram();

		void Bind();
		void Unbind();
		void AttachShaders(unsigned int vertexShaderID, unsigned int fragmentShaderID);
	};
}