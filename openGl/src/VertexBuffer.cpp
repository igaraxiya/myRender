#include "Debug.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
    :m_Count(0)
{
    
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::VertexBuffer(const void* data, unsigned int size, unsigned int count)
    :m_Count(count)
{
    m_RendererID = 0;
}

VertexBuffer::VertexBuffer(const std::vector<float>& data, unsigned int size)
    :m_Count(0)
{
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW));
}

VertexBuffer::VertexBuffer(const std::vector<float>& data, unsigned int size, unsigned int count)
    :m_Count(count)
{
    m_RendererID = 0;
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const 
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

unsigned int VertexBuffer::GetCount() const
{
    return m_Count;
}
