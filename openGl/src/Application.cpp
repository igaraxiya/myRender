#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


#include "test/demo.h"
#include "test/TestTexture2D.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);//垂直同步

    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;
{

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();


    test::Test* currentTest = nullptr;
    test::TestMenu* testMenu = new test::TestMenu(currentTest);
    //TestMenu->m_CurrentTest是currentTest的引用
    //所以每次执行OnRender改变m_CurrentTest实际上是改了currentTest的值
    currentTest = testMenu;

    testMenu->RegisterTest<test::demo>("demo");
    testMenu->RegisterTest<test::TestTexture2D>("TestTexture2D");

    while (!glfwWindowShouldClose(window))
    {

        ImGui_ImplGlfwGL3_NewFrame();

        if (currentTest) {
            currentTest->OnUpDate(1.0f);
            currentTest->OnRender();
            ImGui::Begin("Test");
            if (currentTest != testMenu && ImGui::Button("-<")) {
                delete currentTest;
                currentTest = testMenu;
            }
            currentTest->OnImGuiRender();
            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    delete currentTest;
    if (currentTest != testMenu)
        delete testMenu;

    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
}
    glfwTerminate();
    return 0;
}