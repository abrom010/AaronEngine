#pragma once

#include "DebugOpenGL.h"

#include <iostream>
#include <stb_image.h>

namespace AaronEngine {
	class Texture
	{
	private:
		unsigned int id;
		unsigned int textureUnit;
		int width, height, nrChannels;
	public:
		Texture();
		Texture(unsigned int textureUnit);
		
		void Bind();
		void Unbind();

		void SetTextureUnit(unsigned int textureUnit);
		void AttachImage(std::string filePath);

		static void ActivateTextureUnit(unsigned int textureUnit);
	};
}