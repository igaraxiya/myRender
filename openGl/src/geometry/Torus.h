#pragma once

#include "geometry/Geometry.h"

namespace geometry {
	class Torus :public Geometry {
	public:
		Torus();
		Torus(float innerRadius, float outerRadius);
		Torus(float innerRadius, float outerRadius, layout lay);
		Torus(float innerRadius, float outerRadius, unsigned int prec, layout lay);

		~Torus();

		std::vector<float>& GetVertexBuffer();
		unsigned int GetVertexBufferSize();
		std::vector<unsigned int>& GetIndexBuffer();
		unsigned int GetIndexBufferCount();
	private:
		std::vector<float> m_VertexBuffer;
		unsigned int m_VertexBufferSize;
		std::vector<unsigned int>m_IndexBuffer; 
		unsigned int m_IndexBufferCount;
		unsigned int m_Prec;
		float m_InnerRadius;
		float m_OuterRadius;

		void setIndexBuffer();
		void init(float innerRadius, float outerRadius, unsigned int prec, layout lay);
		void init_Basic();
		void init_Texture();

		std::pair<float, std::pair<float, float> >GetFirstRing(int i);
		std::pair<float, std::pair<float, float> >GetRing(int ring, int vert);

		const float toRadians(float degrees) const { return (degrees * 2.0f * 3.1415926f) / 360.0f; };
	};
}