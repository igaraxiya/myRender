#include "Sphere.h"

namespace geometry {
	Shpere::Shpere()
	{
		init(1.0f, 48, BASIC);
	}

	Shpere::Shpere(float length, layout lay)
	{
		init(length, 48, lay);
	}

	Shpere::Shpere(float length, unsigned int prec, layout lay)
	{
		init(length, prec, lay);
	}

	Shpere::~Shpere()
	{
	}

	std::vector<float>& Shpere::GetVertexBuffer()
	{
		return m_VertexBuffer;
	}
	unsigned int Shpere::GetVertexBufferSize()
	{
		return m_VertexBufferSize;
	}
	std::vector<unsigned int>& Shpere::GetIndexBuffer()
	{
		return m_IndexBuffer;
	}
	unsigned int Shpere::GetIndexBufferCount()
	{
		return m_IndexBufferCount;
	}

	void Shpere::setIndexBuffer()
	{
		for (unsigned int i = 0; i < m_Prec; i++) {
			for (unsigned int j = 0; j < m_Prec; j++) {
				m_IndexBuffer[6 * (i * m_Prec + j) + 0] =    i    * (m_Prec + 1) + j;
				m_IndexBuffer[6 * (i * m_Prec + j) + 1] =    i    * (m_Prec + 1) + j + 1;
				m_IndexBuffer[6 * (i * m_Prec + j) + 2] = (i + 1) * (m_Prec + 1) + j;
				m_IndexBuffer[6 * (i * m_Prec + j) + 3] =    i    * (m_Prec + 1) + j + 1;
				m_IndexBuffer[6 * (i * m_Prec + j) + 4] = (i + 1) * (m_Prec + 1) + j + 1;
				m_IndexBuffer[6 * (i * m_Prec + j) + 5] = (i + 1) * (m_Prec + 1) + j;
			}
		}
	}

	void Shpere::init(float length, unsigned int prec, layout lay)
	{
		m_Prec = prec;
		m_IndexBufferCount = m_Prec * m_Prec * 6;
		m_IndexBuffer = std::vector<unsigned int>(m_IndexBufferCount, 0);
		setIndexBuffer();
		
		if (lay == BASIC) init_Basic(length, prec);
		else if (lay == TEXTURE) init_Texture(length, prec);
		else init_Basic(length, prec);

		m_VertexBufferSize = m_VertexBuffer.size() * sizeof(float);
	}
	void Shpere::init_Basic(float length, unsigned int prec)
	{
		for (unsigned int i = 0; i <= m_Prec; i++) {
			for (unsigned int j = 0; j <= m_Prec; j++) {
				std::pair<float, std::pair<float, float> >pair = getPos(i, j, prec);
				float x = pair.first;
				float y = pair.second.first;
				float z = pair.second.second;
				m_VertexBuffer.push_back(x);
				m_VertexBuffer.push_back(y);
				m_VertexBuffer.push_back(z);
			}
		}
	}
	void Shpere::init_Texture(float length, unsigned int prec)
	{
		for (int i = 0; i <= m_Prec; i++) {
			for (int j = 0; j <= m_Prec; j++) {
				std::pair<float, std::pair<float, float> >pair = getPos(i, j, prec);
				float x = pair.first * length;
				float y = pair.second.first * length;
				float z = pair.second.second * length;
				m_VertexBuffer.push_back(x);
				m_VertexBuffer.push_back(y);
				m_VertexBuffer.push_back(z);

				m_VertexBuffer.push_back((float)j/prec);
				m_VertexBuffer.push_back((float)i/prec);
			}
		}
	}
	std::pair<float, std::pair<float, float>> Shpere::getPos(int i, int j, int prec)
	{
		float x, y, z;

		y = (float)cos(toRadians(180.0f - i * 180.0f/prec));
		x = -(float)cos(toRadians(j * 360.0f / prec)) * (float)abs( cos(asin(y)) );
		z = (float)sin(toRadians(j * 360.0f / prec)) * (float)abs(cos(asin(y)));

		return std::make_pair(x, std::make_pair(y, z));
	}
}
