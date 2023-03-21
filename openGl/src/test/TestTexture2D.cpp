#include "TestTexture2D.h"

test::TestTexture2D::TestTexture2D() :
    m_TranslationA(0.0f, 0.0f, 0.0f), m_TranslationB(0.0f, 0.0f, 0.0f)
{
    float position[] =
    {      0.0f, 0.0f, 0.0f, 0.0f,//0
         100.0f, 0.0f, 1.0f, 0.0f,//1
         100.0f, 100.0f, 1.0f, 1.0f,//2
           0.0f, 100.0f, 0.0f, 1.0f //3
    };
    unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
    };
    m_VertexArray = std::make_unique<VertexArray>();
    m_VertexBuffer = std::make_unique<VertexBuffer>(position, 4 * 4 * sizeof(float));
    m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6);
    m_Renderer = std::make_unique<Renderer>();
    m_Shader = std::make_unique<Shader>("res/shaders/Basic_Texture.shader");
    m_Texture = std::make_unique<Texture>("res/textures/yyy.png");
    m_Proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    m_View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

    VertexBufferLayout layout;
    layout.Push<float>(2);//vertex pos
    layout.Push<float>(2);//texture pos
    m_VertexArray->AddBuffer(*m_VertexBuffer, layout);

    m_Texture->Bind(0);
    m_Shader->setUniform1i("u_Texture", 0);

    m_VertexArray->Unbind();
    m_VertexBuffer->Unbind();
    m_IndexBuffer->Unbind();
    m_Shader->Unbind();
    
}

test::TestTexture2D::~TestTexture2D()
{
}

void test::TestTexture2D::init()
{
}

void test::TestTexture2D::OnUpDate(float deltaTime)
{
}

void test::TestTexture2D::OnRender()
{
    m_Renderer->Clear();
    glm::mat4 model = glm::translate(glm::mat4(1.0), m_TranslationA);
    glm::mat4 mvp = m_Proj * m_View * model;
    {
        m_Shader->Bind();
        m_Shader->setUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);
        m_Shader->setUniformMat4f("u_MVP", mvp);
        m_Renderer->Draw(*m_VertexArray, *m_IndexBuffer, *m_Shader);
    }

    {
        model = glm::translate(glm::mat4(1.0), m_TranslationB);
        mvp = m_Proj * m_View * model;

        m_Shader->Bind();
        m_Shader->setUniform4f("u_Color", 0.0f, 1.0f, 0.0f, 1.0f);
        m_Shader->setUniformMat4f("u_MVP", mvp);
        m_Renderer->Draw(*m_VertexArray, *m_IndexBuffer, *m_Shader);
    }
}

void test::TestTexture2D::OnImGuiRender() {
    ImGui::SliderFloat3("translation A", &m_TranslationA.x, 0.0f, 960.0f);
    ImGui::SliderFloat3("translation B", &m_TranslationB.x, 0.0f, 960.0f);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}
