#pragma once

#include "Graphics/API/VertexArray.h"
#include "Graphics/API/Buffer.h"
#include "Graphics/API/Uniform.h"

namespace Jotunn
{
	class Shader;

	class MeshGeometry
	{
		public:

			MeshGeometry(std::unique_ptr<VertexArray>& vao, std::shared_ptr<VertexBuffer> vbo, const BufferLayout& vbo_layout, std::shared_ptr<IndexBuffer> ibo);
			MeshGeometry();

			~MeshGeometry();

			int GetElementCount()
			{
				return this->ibo->GetCount();
			}
			void Bind();

		protected:

			std::unique_ptr<VertexArray>  vao;
			std::shared_ptr<VertexBuffer> vbo;
			BufferLayout vbo_layout;
			std::shared_ptr<IndexBuffer>  ibo;

			// Setup of geometry - placing geometry data in the buffers, etc. - differ between mesh types
			virtual void SetUpGeometry();
			// Graphics setup - binding of VAO, VBO, IBO, etc. - are common to all mesh geometries
			void SetUpGraphics();

	};

	class MeshMaterial
	{
		public:

			MeshMaterial(std::unique_ptr<std::vector<Uniform*>>& material_uniforms);
			~MeshMaterial();

			void Bind(Shader& shader);

		private:

			std::unique_ptr<std::vector<Uniform*>> uniforms;

	};

	class Mesh
	{
		public:

			Mesh(std::shared_ptr<MeshGeometry> geometry, std::shared_ptr<MeshMaterial> material);
			~Mesh();

			int GetElementCount()
			{
				return this->geometry->GetElementCount();
			}

			void Bind(Shader& shader);

		private:

			std::shared_ptr<MeshGeometry> geometry;
			std::shared_ptr<MeshMaterial> material;
	};
}