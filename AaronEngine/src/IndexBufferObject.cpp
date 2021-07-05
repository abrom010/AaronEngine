#include "IndexBufferObject.h"

namespace AaronEngine {
	IndexBufferObject::IndexBufferObject()
	{
		glGenBuffers(1, &this->id);
		this->indexCount = 0;
	}

	IndexBufferObject::~IndexBufferObject()
	{
		glDeleteBuffers(1, &this->id);
	}

	void IndexBufferObject::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
	}

	void IndexBufferObject::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void IndexBufferObject::AttachData(const void* data, unsigned int count)
	{
		if (!(sizeof(unsigned int) == sizeof(GLuint))) __debugbreak();
		this->indexCount = count;
		this->Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
		this->Unbind();
	}

	unsigned int IndexBufferObject::GetIndexCount()
	{
		return this->indexCount;
	}
}