#pragma once

#include "DebugOpenGL.h"

namespace AaronEngine {
	class VertexBufferObject {
	private:
		unsigned int id;
	public:
		VertexBufferObject();
		~VertexBufferObject();

		void Bind();
		void Unbind();
		void AttachData(const void* data, unsigned int size);
	};
}