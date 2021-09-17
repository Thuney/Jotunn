#pragma once

#include "Graphics/Camera/PerspectiveCamera.h"
#include "Graphics/Render/RenderCommand.h"
#include "Graphics/API/Shader.h"
#include "Graphics/API/Mesh.h"

namespace Jotunn
{
	class Renderer
	{
		public:
			static void Init();

			static void BeginScene(PerspectiveCamera& camera);
			static void EndScene();

			static void Submit(const std::shared_ptr<Shader>& shader, const std::unique_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));
			static void Submit(const std::shared_ptr<Shader>& shader, const std::unique_ptr<Mesh>& mesh, const glm::mat4& transform = glm::mat4(1.0f));

			inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		private:
			struct SceneData
			{
				glm::mat4 ViewProjectionMatrix;
			};

			static SceneData* s_SceneData;
	};
}