#pragma once
#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>

namespace AaronEngine {
	class Sprite {
	public:
		int width, height, nrComponents;
		unsigned char* data;
		//glm::vec2 position;

		Sprite(std::string path);
		//Sprite(std::string path, glm::vec2 position);
		~Sprite();
	};
}