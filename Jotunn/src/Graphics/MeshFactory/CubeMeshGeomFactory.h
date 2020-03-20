#pragma once

#include "Graphics/Mesh.h"
#include "Graphics/MeshFactory/MeshGeomFactory.h"

namespace Jotunn
{
	class CubeMeshGeometry : public MeshGeometry
	{
		public:

			CubeMeshGeometry() : MeshGeometry()
			{
				SetUpGeometry();
				SetUpGraphics();
			};

			~CubeMeshGeometry()
			{
				//delete this->cube_vertices;
				//delete this->triangle_indices;
			};

		private:

			// Hardcoded array of our triangle vertices in (X, Y) pairs
			// Note that these values are in the range [-1.0, 1.0] to fit in
			// OpenGL's unprojected coordinate system
			float cube_vertices[24] =
			{
				-0.5f, 0.0f, 0.5f,
				 0.5f, 0.0f, 0.5f,
				 0.5f, 1.0f, 0.5f,
				-0.5f, 1.0f, 0.5f,

				-0.5f, 0.0f, -0.5f,
				 0.5f, 0.0f, -0.5f,
				 0.5f, 1.0f, -0.5f,
				-0.5f, 1.0f, -0.5f
			};

			// Indices of the triangle vertices in the array of vertex data
			uint32_t triangle_indices[36] =
			{
				3, 0, 1, 3, 1, 2,
				2, 1, 5, 2, 5, 6,
				7, 3, 2, 7, 2, 6,
				6, 5, 4, 6, 4, 7,
				7, 4, 0, 7, 0, 3,
				0, 4, 5, 0, 5, 1,
			};

			virtual void SetUpGeometry() override
			{
				this->vao.reset(VertexArray::Create());
				this->vbo.reset(VertexBuffer::Create(this->cube_vertices, 24 * sizeof(float)));

				Jotunn::BufferLayout layout =
				{
					{ Jotunn::ShaderDataType::Float3, "position" }
				};

				this->vbo_layout = layout;

				int elements = (sizeof(triangle_indices) / sizeof(uint32_t));
				this->ibo.reset(IndexBuffer::Create(triangle_indices, elements));
			};
	};
		
	class CubeMeshGeomFactory : public MeshGeomFactory
	{
		public:

			CubeMeshGeomFactory() : MeshGeomFactory()
			{
				m_Geom = (std::shared_ptr<CubeMeshGeometry>(new CubeMeshGeometry));
			};

		private:

	};
}