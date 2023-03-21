#pragma once

#include <vector>

namespace geometry {
enum layout {
	BASIC, TEXTURE
};

class Geometry {
public:
	Geometry() {}
	virtual ~Geometry() {}
	
	virtual std::vector<float>& GetVertexBuffer() = 0;
	virtual unsigned int GetVertexBufferSize() = 0;

	virtual std::vector<unsigned int>& GetIndexBuffer() = 0;
	virtual unsigned int GetIndexBufferCount() = 0;
};
}

