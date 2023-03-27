#include "Torus.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace geometry {
	Torus::Torus()
	{
		init(1.0f, 2.0f, 48, BASIC);
	}
	Torus::Torus(float innerRadius, float outerRadius)
	{
		init(innerRadius, outerRadius, 48, BASIC);
	}
	Torus::Torus(float innerRadius, float outerRadius, layout lay)
	{
		init(innerRadius, outerRadius, 48, lay);
	}
	Torus::Torus(float innerRadius, float outerRadius, unsigned int prec, layout lay)
	{
		init(innerRadius, outerRadius, prec, lay);
	}
	Torus::~Torus()
	{
	}
	std::vector<float>& Torus::GetVertexBuffer()
	{
		return m_VertexBuffer;
	}
	unsigned int Torus::GetVertexBufferSize()
	{
		return m_VertexBufferSize;
	}
	std::vector<unsigned int>& Torus::GetIndexBuffer()
	{
		return m_IndexBuffer;
	}
	unsigned int Torus::GetIndexBufferCount()
	{
		return m_IndexBufferCount;
	}
	void Torus::setIndexBuffer()
	{
		for (unsigned int ring = 0; ring < m_Prec; ring++) {
			for (unsigned int vert = 0; vert < m_Prec; vert++) {
				m_IndexBuffer[(ring * m_Prec + vert) * 2 * 3 + 0] =    ring    * (m_Prec + 1) + vert;
				m_IndexBuffer[(ring * m_Prec + vert) * 2 * 3 + 1] = (ring + 1) * (m_Prec + 1) + vert;
				m_IndexBuffer[(ring * m_Prec + vert) * 2 * 3 + 2] =    ring    * (m_Prec + 1) + vert + 1;
				m_IndexBuffer[(ring * m_Prec + vert) * 2 * 3 + 3] =    ring    * (m_Prec + 1) + vert + 1;
				m_IndexBuffer[(ring * m_Prec + vert) * 2 * 3 + 4] = (ring + 1) * (m_Prec + 1) + vert;
				m_IndexBuffer[(ring * m_Prec + vert) * 2 * 3 + 5] = (ring + 1) * (m_Prec + 1) + vert + 1;
			}
		}
	}
	void Torus::init(float innerRadius, float outerRadius, unsigned int prec, layout lay)
	{
		m_Prec = prec;
		m_InnerRadius = innerRadius;
		m_OuterRadius = outerRadius;
		m_IndexBufferCount = prec * prec * 6;
		m_IndexBuffer = std::vector<unsigned int>(m_IndexBufferCount, 0);
		setIndexBuffer();

		if (lay == BASIC) init_Basic();
		else if (lay == TEXTURE) init_Texture();
		else init_Basic();

		m_VertexBufferSize = m_VertexBuffer.size() * sizeof(float);
	}
	void Torus::init_Basic()
	{
		for (unsigned int ring = 0; ring < m_Prec + 1; ring++) {
			for (unsigned int vert = 0; vert < m_Prec + 1; vert++) {
				std::pair<float, std::pair<float, float>>pos = GetRing(ring, vert);
				float x = pos.first, y = pos.second.first, z = pos.second.second;

				m_VertexBuffer.push_back(x);
				m_VertexBuffer.push_back(y);
				m_VertexBuffer.push_back(z);

			}
		}
		m_VertexBufferSize = m_VertexBuffer.size() * sizeof(float);
	}
	void Torus::init_Texture()
	{
		for (unsigned int ring = 0; ring < m_Prec + 1; ring++) {
			for (unsigned int vert = 0; vert < m_Prec + 1; vert++) {
				std::pair<float, std::pair<float, float>>pos = GetRing(ring, vert);
				float x = pos.first, y = pos.second.first, z = pos.second.second;

				m_VertexBuffer.push_back(x);
				m_VertexBuffer.push_back(y);
				m_VertexBuffer.push_back(z);

				float s = 2.0f * ring / m_Prec, t = 1.0f * vert / m_Prec;
				if (s > 1.0f) s -= 1.0f; //ÈÆ»Ø0
				m_VertexBuffer.push_back(s);
				m_VertexBuffer.push_back(t);
				
			}
		}
		m_VertexBufferSize = m_VertexBuffer.size() * sizeof(float);
	}
	std::pair<float, std::pair<float, float>> Torus::GetFirstRing(int i)
	{
		float amt = toRadians(i * 360 / m_Prec);

		glm::mat4 rMat = glm::rotate(glm::mat4(1.0f), amt, glm::vec3(0.0f, 0.0f, 1.0f));
		glm::vec3 pos(rMat * glm::vec4(m_OuterRadius, 0.0f, 0.0f, 1.0f));
		pos += glm::vec3(m_InnerRadius, 0.0f, 0.0f);

		return std::make_pair(pos.x, std::make_pair(pos.y, pos.z));
	}
	std::pair<float, std::pair<float, float>> Torus::GetRing(int ring, int vert)
	{
		float amt = toRadians(ring * 360 / m_Prec);
		glm::mat4 rMat = glm::rotate(glm::mat4(1.0f), amt, glm::vec3(0.0f, 0.0f, 1.0f));
		std::pair<float, std::pair<float, float>>R = GetFirstRing(vert);
		glm::vec3 pos = rMat * glm::vec4(R.first, R.second.first, R.second.second, 1.0f);

		return std::make_pair(pos.x, std::make_pair(pos.y, pos.z));
	}
}

