#pragma once

#include "Core/CoreInclude.h"
#include "Graphics/Buffer.h"

namespace Jotunn
{
	class VertexArray
	{
		public:
			virtual ~VertexArray() {}

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexBuffer) = 0;
			virtual void SetIndexBuffer(std::shared_ptr<IndexBuffer> indexBuffer) = 0;

			virtual std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() = 0;
			virtual std::shared_ptr<IndexBuffer> GetIndexBuffer()= 0;

			static VertexArray* Create();
	};
}