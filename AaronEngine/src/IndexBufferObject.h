#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "DebugOpenGL.h"

namespace AaronEngine {
	class IndexBufferObject {
	private:
		unsigned int id;
		unsigned int indexCount;
	public:
		IndexBufferObject();
		~IndexBufferObject();

		void Bind();
		void Unbind();
		void AttachData(const void* data, unsigned int size);
		unsigned int GetIndexCount();
	};
}