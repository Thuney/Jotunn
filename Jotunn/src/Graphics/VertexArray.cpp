#include "Core/CoreInclude.h"
#include "VertexArray.h"

#include "Platform/Graphics/OpenGLVertexArray.h"

namespace Jotunn
{
	VertexArray* VertexArray::Create()
	{
		return new OpenGLVertexArray();
	}
}