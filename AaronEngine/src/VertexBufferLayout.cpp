#include "VertexBufferLayout.h"

namespace AaronEngine {
	VertexBufferLayout::VertexBufferLayout()
	{
		this->stride = 0;
	}

	template<>
	void VertexBufferLayout::AddAttribute<float>(unsigned int count)
	{
		this->attributes.push_back({ GL_FLOAT, count, GL_FALSE });
		this->stride += count * Attribute::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void VertexBufferLayout::AddAttribute<int>(unsigned int count)
	{
		this->attributes.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		this->stride += count * Attribute::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void VertexBufferLayout::AddAttribute<char>(unsigned int count)
	{
		this->attributes.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		this->stride += count * Attribute::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	std::vector<VertexBufferLayout::Attribute> VertexBufferLayout::GetElements()
	{
		return attributes;
	}

	unsigned int VertexBufferLayout::GetStride()
	{
		return this->stride;
	}

	void VertexBufferLayout::ApplyLayout()
	{
		unsigned int offset = 0;
		for (int i = 0; i < this->attributes.size(); i++)
		{
			Attribute attribute = attributes[i];
			glVertexAttribPointer(i, attribute.count, attribute.type, attribute.normalized, this->stride, (const void*)offset);
			glEnableVertexAttribArray(i);
			offset += attribute.count * Attribute::GetSizeOfType(attribute.type);
		}
	}
}