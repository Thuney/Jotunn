#include "Core/CoreInclude.h"
#include "Graphics/VertexArray.h"

#include "Platform/Graphics/OpenGLVertexArray.h"

namespace Jotunn
{
	VertexArray* VertexArray::Create()
	{
		return new OpenGLVertexArray();
	}
}