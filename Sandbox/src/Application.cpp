#include "Window.h"
#include "Renderer.h"

int main()
{
	AaronEngine::Window window(1280, 720, "Sandbox");
	AaronEngine::Renderer renderer;

	while (!window.shouldClose())
	{
		renderer.Clear();
		renderer.Update(window);
	}
}