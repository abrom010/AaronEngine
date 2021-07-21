#include "VertexArrayObject.h"

namespace AaronEngine {
	VertexArrayObject::VertexArrayObject() {
		GLCall(glGenVertexArrays(1, &this->id));
	}

	VertexArrayObject::~VertexArrayObject() {
		GLCall(glDeleteVertexArrays(1, &this->id));
	}

	void VertexArrayObject::Bind() {
		GLCall(glBindVertexArray(this->id));
	}

	void VertexArrayObject::Unbind() {
		GLCall(glBindVertexArray(0));
	}

	void VertexArrayObject::AttachVertexBufferObject(VertexBufferObject& vbo, VertexBufferLayout& vbl) {
		vbo.Bind();
		vbl.ApplyLayout();
	}
}