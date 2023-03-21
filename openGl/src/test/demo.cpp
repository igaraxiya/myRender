#include "demo.h"

test::demo::demo() : 
	position{ 0.0f,   0.0f, 0.0f, 0.0f,//0
         100.0f, 0.0f, 1.0f, 0.0f,//1
         100.0f, 100.0f, 1.0f, 1.0f,//2
         0.0f,   100.0f, 0.0f, 1.0f //3
    },
    indices{
        0, 1, 2,
        2, 3, 0
    },
    translationA(0.0f, 0.0f, 0.0f), translationB(0.0f, 0.0f, 0.0f),
	vao(), vbo(position, 4 * 4 * sizeof(float)), ibo(indices, 6), renderer(), shader("res/shaders/Basic_Texture.shader"), texture("res/textures/yyy.png")
{
    proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    model = glm::translate(glm::mat4(1.0f), translationA);
    mvp = proj * view * model;

    VertexBufferLayout layout;
    layout.Push<float>(2);//vertex pos
    layout.Push<float>(2);//texture pos
    vao.AddBuffer(vbo, layout);

    texture.Bind(0);
    shader.setUniform1i("u_Texture", 0);

    vao.Unbind();
    vbo.Unbind();
    ibo.Unbind();
    shader.Unbind();
}

test::demo::~demo()
{
}

void test::demo::init()
{
}

void test::demo::OnUpDate(float deltaTime)
{
    
}

void test::demo::OnRender()
{
    renderer.Clear();
    {
        model = glm::translate(glm::mat4(1.0), translationA);
        mvp = proj * view * model;

        shader.Bind();
        shader.setUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);
        shader.setUniformMat4f("u_MVP", mvp);
        renderer.Draw(vao, ibo, shader);
    }

    {
        model = glm::translate(glm::mat4(1.0), translationB);
        mvp = proj * view * model;

        shader.Bind();
        shader.setUniform4f("u_Color", 0.1f, 0.0f, 0.8f, 1.0f);
        shader.setUniformMat4f("u_MVP", mvp);
        renderer.Draw(vao, ibo, shader);
    }
}

void test::demo::OnImGuiRender()
{
     ImGui::SliderFloat3("translation A", &translationA.x, 0.0f, 960.0f);
     ImGui::SliderFloat3("translation B", &translationB.x, 0.0f, 960.0f);
     ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}
