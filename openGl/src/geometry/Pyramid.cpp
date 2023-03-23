#include "Pyramid.h"

namespace geometry {
	void Pyramid::init(float length, float width, float height, layout lay)
	{
		if (lay == BASIC) init_Basic(length, width, height);
		else init_Basic(length, width, height);
	}

	void Pyramid::setIndexBuffer() {
		m_IndexBuffer = {
			0, 1, 2,
			0, 2, 3,
			0, 3, 4,
			0, 4, 1,

			1, 4, 3,
			1, 3, 2
		};
		m_IndexBufferCount = 3 * 6;
	}

	void Pyramid::init_Basic(float length, float width, float height)
	{
		/*
		* 原点在底面中心
		*/
		m_VertexBuffer = {
			   0.0f, height,   0.0f,//顶
			-length,      0,  width,//
			 length,      0,  width,//
			 length,      0, -width,//
			-length,      0, -width,//
		};
		m_VertexBufferSize = 5 * 3 * sizeof(float);
		setIndexBuffer();
	}
	Pyramid::Pyramid()
	{
		init(1.0f, 1.0f, 1.0f, BASIC);
	}
	Pyramid::Pyramid(layout lay)
	{
		init(1.0f, 1.0f, 1.0f, lay);
	}
	Pyramid::Pyramid(float length, float width, float height)
	{
		init(length, width, height, BASIC);
	}
	Pyramid::Pyramid(float length, float width, float height, layout lay)
	{
		init(length, width, height, lay);
	}
	Pyramid::~Pyramid()
	{
	}
	std::vector<float>& Pyramid::GetVertexBuffer()
	{
		return m_VertexBuffer;
	}
	unsigned int Pyramid::GetVertexBufferSize()
	{
		return m_VertexBufferSize;
	}
	std::vector<unsigned int>& Pyramid::GetIndexBuffer()
	{
		return m_IndexBuffer;
	}
	unsigned int Pyramid::GetIndexBufferCount()
	{
		return m_IndexBufferCount;
	}
}