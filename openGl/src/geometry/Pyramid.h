#pragma once

#include "geometry/Geometry.h"

namespace geometry {
	class Pyramid : public Geometry{
	public:
		Pyramid();
		Pyramid(layout lay);
		Pyramid(float length, float width, float height);
		Pyramid(float length, float width, float height, layout lay);

		~Pyramid();

		std::vector<float>& GetVertexBuffer();
		unsigned int GetVertexBufferSize();
		std::vector<unsigned int>& GetIndexBuffer();
		unsigned int GetIndexBufferCount();

	private:
		std::vector<float> m_VertexBuffer;
		unsigned int m_VertexBufferSize;
		std::vector<unsigned int>m_IndexBuffer;
		unsigned int m_IndexBufferCount;

		void setIndexBuffer();
		void init(float length, float width, float height, layout lay);
		void init_Basic(float length, float width, float height);
	};
}