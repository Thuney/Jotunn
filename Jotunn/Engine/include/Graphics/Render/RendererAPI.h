#pragma once

#include "Graphics/API/Mesh.h"
#include "glm/glm.hpp"
#include <memory>

namespace Jotunn
{
	class RendererAPI
	{
		public:
			enum class API
			{
				None = 0, OpenGL = 1
			};

		public:
			virtual void Init() = 0;
			virtual void SetClearColor(const glm::vec4& color) = 0;
			virtual void Clear() = 0;

			virtual void DrawIndexed(const std::unique_ptr<VertexArray>& vertexArray) = 0;
			virtual void DrawIndexed(const std::unique_ptr<Mesh>& mesh) = 0;

			inline static API GetAPI() { return s_API; }

		private:
			static API s_API;
	};
}