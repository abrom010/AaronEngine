#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace AaronEngine {
	class VertexBuffer
	{
	private:
		unsigned int id;
	public:
		VertexBuffer();
		~VertexBuffer();

		void Bind();
		void Unbind();
		void AttachData(const void* data, unsigned int size);
	};
}