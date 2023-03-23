#pragma once

#include "geometry/Cube.h"
#include "geometry/Pyramid.h"
#include "Test.h"

namespace test {
	class CubeTest : public Test {
	public:
		CubeTest();
		~CubeTest();

		void init() override;
		void OnUpDate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

		glm::vec3 translationA, translationB;

	private:
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<Renderer> m_Renderer;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<Texture> m_Texture;

		glm::mat4 m_Proj, m_View, m_Model;
		float x_Rotate, y_Rotate, z_Rotate;
	};

}