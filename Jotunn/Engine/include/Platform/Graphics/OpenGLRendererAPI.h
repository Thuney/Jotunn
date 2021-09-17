#pragma once

#include "Graphics/Render/RendererAPI.h"

namespace Jotunn
{
	class OpenGLRendererAPI : public RendererAPI
	{
		public:
			virtual void Init() override;

			virtual void SetClearColor(const glm::vec4& color) override;
			virtual void Clear() override;

			virtual void DrawIndexed(const std::unique_ptr<VertexArray>& vertexArray) override;
			virtual void DrawIndexed(const std::unique_ptr<Mesh>& mesh) override;
	};
}