#include "Cube.h"

namespace geometry {
	std::vector<float>& Cube::GetVertexBuffer()
	{
		return m_VertexBuffer;
	}
	std::vector<unsigned int>& Cube::GetIndexBuffer()
	{
		return m_IndexBuffer;
	}
	Cube::Cube()
	{
		init(1.0f, BASIC);
	}

	Cube::Cube(float length)
	{
		init(length, BASIC);
	}

	Cube::Cube(float length, layout lay)
	{
		init(length, lay);
	}

	Cube::Cube(float x_length, float y_length, float z_length)
	{
		init(x_length, y_length, z_length, BASIC);
	}

	Cube::Cube(float x_length, float y_length, float z_length, layout lay)
	{
		init(x_length, y_length, z_length, lay);
	}

	void Cube::setIndexBuffer()
	{
		/*
		* 前 右 后 左 上 下
		* 三角形先左后右
		*/
		m_IndexBuffer = {
			1, 2, 4,
			2, 3, 4,

			2, 6, 3,
			6, 7, 3,

			6, 5, 7,
			5, 8, 7,

			5, 1, 8,
			1, 4, 8,

			4, 3, 8,
			3, 7, 8,

			5, 6, 1,
			6, 3, 1
		};
	}

	void Cube::init(float length, layout lay)
	{
		init(length, length, length, lay);
	}

	void Cube::init(float x_length, float y_length, float z_length, layout lay) {
		if (lay == BASIC) init_Basic(x_length, y_length, z_length);

		else init_Basic(x_length, y_length, z_length);
	}

	void Cube::init_Basic(float x_length, float y_length, float z_length)
	{
		/*
		* 中心点为原点
		* 从左前下 角开始逆时针、前->后面构造顶点, 上下的贴图底朝前，其他均旋转后相同
		* 仅顶点位置
		*/
		m_VertexBuffer = {
			-x_length, -y_length,  z_length,//0
			 x_length, -y_length,  z_length,//2
			 x_length,  y_length,  z_length,//3
			-x_length,  y_length,  z_length,//4
			

			-x_length, -y_length, -z_length,//5
			 x_length, -y_length, -z_length,//6
			 x_length,  y_length, -z_length,//7
			-x_length,  y_length, -z_length //8
		};
		setIndexBuffer();
	}

	void Cube::init_Texture(float x_length, float y_length, float z_length)
	{
		m_VertexBuffer = {

		};
		m_IndexBuffer = {

		};
		setIndexBuffer();
	}

}