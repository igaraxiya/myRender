#pragma once

#include "Test.h"
#include <memory>

namespace test {
	class TestTexture2D : public Test{
	public:
		TestTexture2D();
		~TestTexture2D();

		void init() override;
		void OnUpDate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<Renderer> m_Renderer;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<Texture> m_Texture;

		glm::mat4 m_Proj, m_View, m_Model;
		glm::vec3 m_TranslationA, m_TranslationB;
	};
}