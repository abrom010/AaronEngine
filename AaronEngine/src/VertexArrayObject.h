#pragma once

#include "DebugOpenGL.h"

#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"

namespace AaronEngine {
	class VertexArrayObject {
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