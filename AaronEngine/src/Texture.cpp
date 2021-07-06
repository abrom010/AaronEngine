#include "Texture.h"

namespace AaronEngine {
	Texture::Texture()
		: width(0), height(0), nrChannels(0), textureUnit(GL_TEXTURE0)
	{
		GLCall(glActiveTexture(textureUnit));
		GLCall(glGenTextures(1, &this->id));
	}

	Texture::Texture(unsigned int textureUnit)
		: width(0), height(0), nrChannels(0), textureUnit(textureUnit)
	{
		GLCall(glActiveTexture(textureUnit));
		GLCall(glGenTextures(1, &this->id));
	}

	void Texture::Bind()
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, this->id));
	}

	void Texture::Unbind()
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}

	void Texture::SetTextureUnit(unsigned int textureUnit)
	{
		this->textureUnit = textureUnit;
	}

	void Texture::AttachImage(std::string filePath)
	{
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

		unsigned char* data = stbi_load(filePath.c_str(), &this->width, &height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load image" << std::endl;
		}
		stbi_image_free(data);
	}

	static void ActivateTextureUnit(unsigned int textureUnit)
	{
		GLCall(glActiveTexture(textureUnit));
	}
}