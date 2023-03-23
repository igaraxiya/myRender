#pragma once

#include <vector>

class VertexBuffer {
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	VertexBuffer(const void* data, unsigned int size);
	VertexBuffer(const void* data, unsigned int size, unsigned int count);
	VertexBuffer(const std::vector<float>& data, unsigned int size);
	VertexBuffer(const std::vector<float>& data, unsigned int size, unsigned int count);
	~VertexBuffer();

	void Bind() const ;
	void Unbind() const ;
	unsigned int GetCount() const;
};