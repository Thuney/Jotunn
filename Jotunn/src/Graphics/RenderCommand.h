#pragma once

#include "RendererAPI.h"
#include "glm/glm.hpp"
#include <memory>

namespace Jotunn
{
	class RenderCommand
	{
		public:
			inline static void Init()
			{
				s_RendererAPI->Init();
			}

			inline static void SetClearColor(const glm::vec4& color)
			{
				s_RendererAPI->SetClearColor(color);
			}

			inline static void Clear()
			{
				s_RendererAPI->Clear();
			}

			inline static void DrawIndexed(const std::unique_ptr<VertexArray>& vertexArray)
			{
				s_RendererAPI->DrawIndexed(vertexArray);
			}

			inline static void DrawIndexed(const std::unique_ptr<Mesh>& mesh)
			{
				s_RendererAPI->DrawIndexed(mesh);
			}

		private:
			static RendererAPI* s_RendererAPI;
	};
}