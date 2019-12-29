#pragma once

#include "VertexArray.h"
#include "Buffer.h"
#include "Uniform.h"

namespace Jotunn
{
	class Shader;

	class MeshGeometry
	{
		public:

			MeshGeometry(const std::shared_ptr<VertexArray>& vao, const std::shared_ptr<VertexBuffer>& vbo, const BufferLayout& vbo_layout, const std::shared_ptr<IndexBuffer>& ibo);
			~MeshGeometry();

			int GetElementCount()
			{
				return this->ibo->GetCount();
			}
			void Bind();

		private:

			std::shared_ptr<VertexArray>  vao;
			std::shared_ptr<VertexBuffer> vbo;
			BufferLayout vbo_layout;
			std::shared_ptr<IndexBuffer>  ibo;

			void SetUpGeometry()
			{
				this->vbo->SetLayout(this->vbo_layout);
				this->vao->AddVertexBuffer(this->vbo);
				this->vao->SetIndexBuffer(this->ibo);
			}
	};

	class MeshMaterial
	{
		public:

			MeshMaterial(const std::shared_ptr<std::vector<Uniform*>>& material_uniforms);
			~MeshMaterial();

			void Bind(Shader& shader);

		private:

			std::shared_ptr<std::vector<Uniform*>> uniforms;

	};

	class Mesh
	{
		public:

			Mesh(MeshGeometry* geometry, MeshMaterial* material);
			~Mesh();

			int GetElementCount()
			{
				return this->geometry->GetElementCount();
			}

			void Bind(Shader& shader);

		private:

			MeshGeometry* geometry;
			MeshMaterial* material;
	};
}