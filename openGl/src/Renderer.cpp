#include <iostream>

#include "Renderer.h"

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const
{
    vao.Bind();
    ibo.Bind();
    shader.Bind();
    
    GLCall(glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(const VertexArray& vao, const VertexBuffer& vbo, const Shader& shader) const
{
    vao.Bind();
    vbo.Bind();
    shader.Bind();

    GLCall(glDrawArrays(GL_TRIANGLES, 0, vbo.GetCount()));
}
