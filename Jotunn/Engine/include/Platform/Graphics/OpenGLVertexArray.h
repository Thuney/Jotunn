#pragma once

#include "Graphics/API/VertexArray.h"

namespace Jotunn
{
	class OpenGLVertexArray : public VertexArray
	{
		public:
			OpenGLVertexArray();
			virtual ~OpenGLVertexArray();

			virtual void Bind() const override;
			virtual void Unbind() const override;

			virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexBuffer) override;
			virtual void SetIndexBuffer(std::shared_ptr<IndexBuffer> indexBuffer) override;

			virtual std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() { return m_VertexBuffers; }
			virtual std::shared_ptr<IndexBuffer> GetIndexBuffer() { return m_IndexBuffer; }

		private:
			uint32_t m_RendererID;
			uint32_t m_VertexBufferIndex = 0;
			std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
			std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};
}