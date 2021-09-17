#include "Core/CoreInclude.h"
#include "Graphics/API/Buffer.h"

#include "Platform/Graphics/OpenGLBuffer.h"

namespace Jotunn
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		return new OpenGLVertexBuffer(vertices, size);
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		return new OpenGLIndexBuffer(indices, size);
	}
}
