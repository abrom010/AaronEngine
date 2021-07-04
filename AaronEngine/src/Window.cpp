#include "Window.h"

#include <iostream>

namespace AaronEngine {
	Window::Window() {}

	Window::Window(int width, int height, const char* title)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->window = glfwCreateWindow(width, height, title, NULL, NULL);
		this->width = width;
		this->height = height;

		if (this->window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			this->close = true;
		}
		glfwMakeContextCurrent(this->window);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::shouldClose()
	{
		return close || glfwWindowShouldClose(this->window);
	}
}