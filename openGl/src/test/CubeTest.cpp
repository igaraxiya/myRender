#include "CubeTest.h"

namespace test {
	CubeTest::CubeTest() : x_Rotate(0.0f), y_Rotate(0.0f), z_Rotate(0.0f)
	{
        //geometry::Cube cube(1.0f, geometry::TEXTURE);
        //geometry::Pyramid cube(0.5f, 0.5f, 1.0f, geometry::TEXTURE);
        geometry::Shpere cube(1.0f, 48, geometry::TEXTURE);

        m_VertexArray = std::make_unique<VertexArray>();
        m_VertexBuffer = std::make_unique<VertexBuffer>(cube.GetVertexBuffer(), cube.GetVertexBufferSize());
        m_IndexBuffer = std::make_unique<IndexBuffer>(cube.GetIndexBuffer(),cube.GetIndexBufferCount());
        m_Renderer = std::make_unique<Renderer>();
        m_Shader = std::make_unique<Shader>("res/shaders/Basic_Texture.shader");
        m_Texture = std::make_unique<Texture>("res/textures/yyy.png");

        m_Proj = glm::perspective(1.0472f, 960.0f / 540.f, 0.1f, 500.0f);//Õ∏ ”æÿ’Û
        //m_Proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
        m_View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -8.0f));
        m_Model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -2.0f, 0.0f));

        VertexBufferLayout layout;
        layout.Push<float>(3);//vertex pos
        layout.Push<float>(2);//texture pos
        m_VertexArray->AddBuffer(*m_VertexBuffer, layout);

        m_Texture->Bind(0);
        m_Shader->setUniform1i("u_Texture", 0);

        m_VertexArray->Unbind();
        m_VertexBuffer->Unbind();
        m_IndexBuffer->Unbind();
        m_Shader->Unbind();
	}

    CubeTest::~CubeTest()
    {
    }

    void CubeTest::init()
    {
    }

    void CubeTest::OnUpDate(float deltaTime)
    {
    }

    void CubeTest::OnRender()
    {
        m_Renderer->Clear();
        glClear(GL_DEPTH_BUFFER_BIT);
        //glDisable(GL_CULL_FACE);
        
        glm::mat4 model = glm::rotate(m_Model, x_Rotate, glm::vec3(1.0f, 0.0f, 0.0f));
                  model = glm::rotate(model,   y_Rotate, glm::vec3(0.0f, 1.0f, 0.0f));
                  model = glm::rotate(model,   z_Rotate, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 mvp = m_Proj * m_View * model;

        {
            GLCall(glEnable(GL_DEPTH_TEST));
            m_Shader->Bind();
            m_Shader->setUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);
            m_Shader->setUniformMat4f("u_MVP", mvp);
            m_Renderer->Draw(*m_VertexArray, *m_IndexBuffer, *m_Shader);
        }

    }

    void CubeTest::OnImGuiRender()
    {
        ImGui::Text("Cube");
        ImGui::SliderFloat("RotateX", &x_Rotate, -3.0f, 3.0f);
        ImGui::SliderFloat("RotateY", &y_Rotate, -3.0f, 3.0f);
        ImGui::SliderFloat("RotateZ", &z_Rotate, -3.0f, 3.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }

}
