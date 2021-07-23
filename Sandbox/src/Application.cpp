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

int main() {
	AaronEngine::Window window(1280, 720, "Sandbox");
	AaronEngine::Renderer renderer(window);

	AaronEngine::Model pb("models/chunky.obj", false);

	AaronEngine::Model halal("models/halal.obj", false);
	halal.transform = glm::rotate(halal.transform, glm::radians(90.0f), glm::vec3(1, 0, 0));

	AaronEngine::Sprite sprite("red.png");
	AaronEngine::Sprite sprite2("black.png");
	sprite2.position.x = window.GetWidth() - sprite.width;
	sprite2.position.y = window.GetHeight() - sprite.height;

	bool moveRight = true, moveDown = true;
	bool moveRight2 = false, moveDown2 = false;

	renderer.SetBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	while (!window.shouldClose()) {
		renderer.Clear();

		pb.transform = glm::rotate(pb.transform, 1.0f, glm::vec3(1, 1, 0));
		renderer.DrawModel(pb);

		for (int j = -10; j < 11; j += 2) {
			for (int i = -10; i < 11; i += 2) {
				halal.transform = glm::mat4(1.0f);
				halal.transform = glm::translate(halal.transform, glm::vec3(i, j, -2));
				halal.transform = glm::rotate(halal.transform, glm::radians(90.0f), glm::vec3(1, 0, 0));
				renderer.DrawModel(halal);
			}
		}
		

		if (sprite.position.x > window.GetWidth() - sprite.width)
			moveRight = false;
		else if (sprite.position.x < 0)
			moveRight = true;
		if (sprite.position.y > window.GetHeight() - sprite.height)
			moveDown = false;
		else if (sprite.position.y < 0)
			moveDown = true;
		
		if(moveRight)
			sprite.position = glm::vec2(sprite.position.x + 80.0f, sprite.position.y);
		else
			sprite.position = glm::vec2(sprite.position.x - 80.0f, sprite.position.y);
		if(moveDown)
			sprite.position = glm::vec2(sprite.position.x, sprite.position.y + 80.0f);
		else
			sprite.position = glm::vec2(sprite.position.x, sprite.position.y - 80.0f);
		renderer.DrawSprite(sprite);

		if (sprite2.position.x > window.GetWidth() - sprite2.width)
			moveRight2 = false;
		else if (sprite2.position.x < 0)
			moveRight2 = true;
		if (sprite2.position.y > window.GetHeight() - sprite2.height)
			moveDown2 = false;
		else if (sprite2.position.y < 0)
			moveDown2 = true;

		if (moveRight2)
			sprite2.position = glm::vec2(sprite2.position.x + 80.0f, sprite2.position.y);
		else
			sprite2.position = glm::vec2(sprite2.position.x - 80.0f, sprite2.position.y);
		if (moveDown2)
			sprite2.position = glm::vec2(sprite2.position.x, sprite2.position.y + 80.0f);
		else
			sprite2.position = glm::vec2(sprite2.position.x, sprite2.position.y - 80.0f);
		renderer.DrawSprite(sprite2);
		
		renderer.Update();
	}
}