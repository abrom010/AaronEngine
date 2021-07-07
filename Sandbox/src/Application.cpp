#include "Window.h"
#include "Renderer.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"
#include "Shader.h"

#include "Model.h"

int main()
{
	AaronEngine::Window window(1280, 720, "Sandbox");
	AaronEngine::Renderer renderer(window);

	renderer.SetBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);

	AaronEngine::Model model("mushroom.obj", false);
	
	while (!window.shouldClose())
	{
		renderer.Clear();
		//renderer.DrawModel(model);
		renderer.Update();
	}
}