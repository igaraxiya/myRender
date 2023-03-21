#pragma once

#include <functional>
#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

namespace test {
	class Test {
	public:
		Test() {}; //init
		virtual ~Test() {};

		virtual void init() {}
		virtual void OnUpDate(float deltaTime) {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}
	};


	class TestMenu : public Test {
	public:
		TestMenu(Test* & currentTestPointer);

		template<typename T>
		void RegisterTest(const std::string& name) {
			std::cout << "Registering test " << name << std::endl;
			m_Tests.push_back(std::make_pair ( name, []() { return new T(); } ) );
		}
		void OnRender() override;
		void OnImGuiRender() override;
	private:
		Test* & m_CurrentTest;
		std::vector<std::pair<std::string, std::function<Test* ()> > > m_Tests;
	};
}