#include "Renderer.h"

namespace AaronEngine {
	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{

	}

	void Renderer::SetBackgroundColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::Update(Window& window)
	{
		glfwSwapBuffers(window.GetWindow());
		glfwPollEvents();
	}

}