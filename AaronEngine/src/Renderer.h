#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.h"

namespace AaronEngine {
	class Renderer
	{
	private:
	public:
		Renderer();
		~Renderer();

		void SetBackgroundColor(float r, float g, float b, float a);
		void Clear();
		void Update(Window& window);
	};
}