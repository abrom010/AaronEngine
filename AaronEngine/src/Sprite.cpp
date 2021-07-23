#include "Sprite.h"

#include <stb_image.h>

namespace AaronEngine {
	Sprite::Sprite(std::string path) {
		data = stbi_load(path.c_str(), &width, &height, &nrComponents, 0);
		//position = glm::vec2(0, 0);
	}

	/*Sprite::Sprite(std::string path, glm::vec2 position) {
		data = stbi_load(path.c_str(), &width, &height, &nrComponents, 0);
		position = position;
	}*/

	Sprite::~Sprite() {
		stbi_image_free(data);
	}
}