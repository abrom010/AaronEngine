#include "IndexBufferObject.h"

namespace AaronEngine {
	IndexBufferObject::IndexBufferObject() : indexCount(0) {
		GLCall(glGenBuffers(1, &this->id));
	}

	IndexBufferObject::~IndexBufferObject() {
		GLCall(glDeleteBuffers(1, &this->id));
	}

	void IndexBufferObject::Bind() {
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id));
	}

	void IndexBufferObject::Unbind() {
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	void IndexBufferObject::AttachData(const void* data, unsigned int count) {
		if (!(sizeof(unsigned int) == sizeof(GLuint))) __debugbreak();
		this->indexCount = count;
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
	}

	unsigned int IndexBufferObject::GetIndexCount() {
		return this->indexCount;
	}
}