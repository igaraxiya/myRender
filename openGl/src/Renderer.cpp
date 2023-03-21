#include <iostream>

#include "Renderer.h"

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const Shader& shader) const
{
    vao.Bind();
    ibo.Bind();
    shader.Bind();
    GLCall(glEnable(GL_DEPTH_TEST));
    GLCall(glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr));
}