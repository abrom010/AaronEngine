#include "VertexBuffer.h"

namespace AaronEngine {
	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &this->id);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &this->id);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->id);
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::AttachData(const void* data, unsigned int size)
	{
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		this->Unbind();
	}
}