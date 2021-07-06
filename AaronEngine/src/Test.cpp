#include "Window.h"
#include "Renderer.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"
#include "Shader.h"

int main()
{
	AaronEngine::Window window(1280, 720, "Sandbox");
	AaronEngine::Renderer renderer(window);

	//renderer.SetBackgroundColor(1.0f, 1.0f, 1.0f, 1.0f);

	while (!window.shouldClose())
	{
		renderer.DrawTriangle();
		renderer.Update();
	}
}