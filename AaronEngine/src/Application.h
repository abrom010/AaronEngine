#pragma once
#include "Window.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace AaronEngine {
	class Application
	{
	private:
		Window window;
		bool close;
	public:
		Application();
		Application(int windowWidth, int windowHeight, const char* windowTitle);
		~Application();

		bool shouldClose();
		void Run();
	};
}

