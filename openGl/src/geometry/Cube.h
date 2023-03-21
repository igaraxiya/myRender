#pragma once

#include "geometry/Geometry.h"

namespace geometry {

	class Cube :public Geometry {
	public:
		virtual std::vector<float>& GetVertexBuffer() override;
		virtual std::vector<unsigned int>& GetIndexBuffer() override;

		Cube();
		Cube(float length);
		Cube(float length, layout lay);
		Cube(float x_length, float y_length, float z_length);
		Cube(float x_length, float y_length, float z_length, layout lay);
	private:
		std::vector<float>m_VertexBuffer;
		std::vector<unsigned int>m_IndexBuffer;

		void setIndexBuffer();
		void init(float length, layout lay);
		void init(float x_length, float y_length, float z_length, layout lay);
		void init_Basic(float x_length, float y_length, float z_length);
		void init_Texture(float x_length, float y_length, float z_length);
	};

}