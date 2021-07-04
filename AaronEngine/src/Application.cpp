#include "Application.h"

#include <iostream>

namespace AaronEngine {
	Application::Application() {}

	Application::Application(int windowWidth, int windowHeight, const char* windowTitle)
	{
		this->close = false;
		this->window = Window(windowWidth, windowHeight, windowTitle);
		if (window.shouldClose()) this->close = true;

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			this->close = true;
		}
	}

	Application::~Application()
	{
		
	}

	bool Application::shouldClose()
	{
		return this->close;
	}

	void Application::Run()
	{
		while (!this->shouldClose() && !this->window.shouldClose())
		{

		}
	}

}

