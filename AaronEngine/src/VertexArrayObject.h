#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"

namespace AaronEngine {
	class VertexArrayObject
	{
	private:
		unsigned int id;
	public:
		VertexArrayObject();
		~VertexArrayObject();

		void Bind();
		void Unbind();

		void AttachVertexBufferObject(VertexBufferObject& vbo, VertexBufferLayout& vbl);
	};
}