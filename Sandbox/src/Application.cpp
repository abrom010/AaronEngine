#include "Window.h"
#include "Renderer.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"
#include "Shader.h"

#include "Model.h"

int main() {
	AaronEngine::Window window(1280, 720, "Sandbox");
	AaronEngine::Renderer renderer(window);

	renderer.SetBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);

	AaronEngine::Model pb("chunky.obj", false);
	AaronEngine::Model halal("halal.obj", false);
	halal.transform = glm::translate(halal.transform, glm::vec3(3, 0, 0));
	AaronEngine::Model halal2("halal.obj", false);
	halal2.transform = glm::translate(halal2.transform, glm::vec3(-3, 0, 0));
	
	while (!window.shouldClose()) {
		renderer.Clear();
		pb.transform = glm::rotate(pb.transform, 0.1f, glm::vec3(0, 1, 0));
		renderer.DrawModel(pb);
		
		halal.transform = glm::rotate(halal.transform, 0.1f, glm::vec3(1, 0, 0));
		renderer.DrawModel(halal);

		halal2.transform = glm::rotate(halal2.transform, 0.1f, glm::vec3(1, 0, 0));
		renderer.DrawModel(halal2);
		renderer.Update();
	}
}