#include "Test.h"

namespace test {

	TestMenu::TestMenu(Test*& currentTestPointer): 
		m_CurrentTest(currentTestPointer)
	{
	}

	void TestMenu::OnRender() {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void TestMenu::OnImGuiRender()
	{
		for (auto& test : m_Tests) {
			if (ImGui::Button(test.first.c_str())) {
				m_CurrentTest = test.second();
			}
		}
	}


}
