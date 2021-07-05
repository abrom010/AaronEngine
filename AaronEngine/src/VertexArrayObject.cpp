#include "VertexArrayObject.h"

namespace AaronEngine {
	VertexArrayObject::VertexArrayObject()
	{
		glGenVertexArrays(1, &this->id);
	}

	VertexArrayObject::~VertexArrayObject()
	{
		glDeleteVertexArrays(1, &this->id);
	}

	void VertexArrayObject::Bind()
	{
		glBindVertexArray(this->id);
	}

	void VertexArrayObject::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArrayObject::AttachVertexBufferObject(VertexBufferObject& vbo, VertexBufferLayout& vbl)
	{
		this->Bind();
		vbo.Bind();
		vbl.ApplyLayout();
		this->Unbind();
	}
}