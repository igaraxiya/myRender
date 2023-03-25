#pragma once

#include "geometry/Geometry.h"

namespace geometry {
	class Shpere : public Geometry {
	public:
		Shpere();
		Shpere(float length, layout lay);
		Shpere(float length, unsigned int prec, layout lay);

		~Shpere();
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

		void setIndexBuffer();
		void init(float length, unsigned int prec, layout lay);
		void init_Basic(float length, unsigned int prec);
		void init_Texture(float length, unsigned int prec);

		std::pair<float, std::pair<float, float> >getPos(int i, int j, int prec);
		const float toRadians(float degrees) const { return (degrees * 2.0f * 3.1415926f) / 360.0f; };
	};
}