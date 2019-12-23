#pragma once

#include "VertexArray.h"
#include "Buffer.h"

namespace Jotunn
{
	class MeshGeometry
	{
		public:

			MeshGeometry(std::shared_ptr<VertexArray> vao, std::shared_ptr<VertexBuffer> vbo, const BufferLayout& vbo_layout, std::shared_ptr<IndexBuffer> ibo);
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

			MeshMaterial()
			{

			}

			~MeshMaterial()
			{

			}

		private:

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
			void Bind();

		private:

			MeshGeometry* geometry;
			MeshMaterial* material;
	};
}