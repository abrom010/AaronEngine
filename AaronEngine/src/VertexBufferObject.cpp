#include "VertexBufferObject.h"

namespace AaronEngine {
	VertexBufferObject::VertexBufferObject() {
		GLCall(glGenBuffers(1, &this->id));
	}

	VertexBufferObject::~VertexBufferObject() {
		GLCall(glDeleteBuffers(1, &this->id));
	}

	void VertexBufferObject::Bind() {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, this->id));
	}

	void VertexBufferObject::Unbind() {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void VertexBufferObject::AttachData(const void* data, unsigned int size) {
		GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}
}