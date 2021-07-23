#pragma once

#include "DebugOpenGL.h"
#include <GLFW/glfw3.h>

namespace AaronEngine {
	class Window {
	private:
		GLFWwindow* window;
		int width, height;
		bool close;
	public:
		Window(int width, int height, const char* title);
		~Window();

		bool shouldClose();
		void Update();
		GLFWwindow* GetWindow();
		int GetWidth();
		int GetHeight();
	};
}
