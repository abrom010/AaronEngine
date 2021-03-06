#include "Window.h"

#include <iostream>

namespace AaronEngine {
	Window::Window(int width, int height, const char* title) : width(width), height(height), close(false) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->window = glfwCreateWindow(width, height, title, NULL, NULL);

		if (this->window == NULL) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			this->close = true;
		}
		glfwMakeContextCurrent(this->window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			this->close = true;
		}
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::shouldClose() {
		return this->close || glfwWindowShouldClose(this->window);
	}

	GLFWwindow* Window::GetWindow() {
		return this->window;
	}

	int Window::GetWidth() {
		return width;
	}

	int Window::GetHeight() {
		return height;
	}
}