#pragma once

#include "Test.h"

namespace test {
	class demo : public Test {
	public:
		demo();
		~demo();

		void init() override;
		void OnUpDate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

		glm::vec3 translationA, translationB;

	private:
		float position[16];
		unsigned int indices[6];

		glm::mat4 proj, view, model, mvp;

		VertexArray vao;
		VertexBuffer vbo;
		IndexBuffer ibo;
		Renderer renderer;
		Shader shader;
		Texture texture;
	};

}