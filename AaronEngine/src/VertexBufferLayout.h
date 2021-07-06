#pragma once

#include "DebugOpenGL.h"

#include <vector>

namespace AaronEngine {
	class VertexBufferLayout
	{
	public:
		struct Attribute
		{
			unsigned int type;
			unsigned int count;
			unsigned char normalized;

			static unsigned int GetSizeOfType(unsigned int type)
			{
				switch (type)
				{
				case GL_FLOAT:			return 4;
				case GL_UNSIGNED_INT:	return 4;
				case GL_UNSIGNED_BYTE:	return 1;
				}
				return 0;
			}
		};

	private:
		unsigned int stride;
		std::vector<Attribute> attributes;

	public:
		VertexBufferLayout();

		template<typename T>
		void AddAttribute(unsigned int count);

		template<>
		void AddAttribute<float>(unsigned int count);

		template<>
		void AddAttribute<int>(unsigned int count);

		template<>
		void AddAttribute<char>(unsigned int count);

		std::vector<Attribute> GetAttributes();
		unsigned int GetStride();

		void ApplyLayout();
	};
}