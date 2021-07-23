#include "Window.h"
#include "Renderer.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"
#include "IndexBufferObject.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "Model.h"
#include "Sprite.h"

#include "SoundDevice.h"
#include "SoundBuffer.h"
#include "SoundSource.h"
#include "MusicBuffer.h"

int main() {
	AaronEngine::SoundDevice::init();
	AaronEngine::SoundSource speaker;

	uint32_t sound = AaronEngine::SoundBuffer::get()->addSoundEffect("sounds/mars.ogg");
	
	AaronEngine::MusicBuffer music("music/delilah.ogg");

	AaronEngine::Window window(1280, 720, "Sandbox");
	AaronEngine::Renderer renderer(window);

	AaronEngine::Model pb("models/chunky.obj", false);

	renderer.SetBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	//music.Play();
	while (!window.shouldClose()) {
		renderer.Clear();
		renderer.DrawModel(pb);
		renderer.Update();

		if (glfwGetKey(window.GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window.GetWindow(), true);
		if (glfwGetMouseButton(window.GetWindow(), GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
			speaker.Play(sound);


		//music.Update();
	}
}