#include "VertexBufferObject.h"

namespace AaronEngine {
	VertexBufferObject::VertexBufferObject()
	{
		glGenBuffers(1, &this->id);
	}

	VertexBufferObject::~VertexBufferObject()
	{
		glDeleteBuffers(1, &this->id);
	}

	void VertexBufferObject::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->id);
	}

	void VertexBufferObject::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBufferObject::AttachData(const void* data, unsigned int size)
	{
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		this->Unbind();
	}
}