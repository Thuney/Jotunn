#include "Core/CoreInclude.h"
#include "Platform/Graphics/OpenGLVertexArray.h"
#include "GL/glew.h"

namespace Jotunn
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case Jotunn::ShaderDataType::Float:    return GL_FLOAT;
			case Jotunn::ShaderDataType::Float2:   return GL_FLOAT;
			case Jotunn::ShaderDataType::Float3:   return GL_FLOAT;
			case Jotunn::ShaderDataType::Float4:   return GL_FLOAT;
			case Jotunn::ShaderDataType::Mat3:     return GL_FLOAT;
			case Jotunn::ShaderDataType::Mat4:     return GL_FLOAT;
			case Jotunn::ShaderDataType::Int:      return GL_INT;
			case Jotunn::ShaderDataType::Int2:     return GL_INT;
			case Jotunn::ShaderDataType::Int3:     return GL_INT;
			case Jotunn::ShaderDataType::Int4:     return GL_INT;
			case Jotunn::ShaderDataType::Bool:     return GL_BOOL;
		}

		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexBuffer)
	{
		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.Type), element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)(intptr_t)element.Offset);
			m_VertexBufferIndex++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<IndexBuffer> indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}
}