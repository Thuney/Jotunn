#pragma once

#include "Graphics/Mesh.h"
#include "Graphics/MeshFactory/MeshGeomFactory.h"

namespace Jotunn
{
	class SphereMeshGeometry : public MeshGeometry
	{
		public:

			SphereMeshGeometry() : MeshGeometry()
			{
				SetUpGeometry();
				SetUpGraphics();

			};

			~SphereMeshGeometry()
			{

			};

		protected:

			virtual void SetUpGeometry() override
			{
				//this->vao.reset(VertexArray::Create());
				//this->vbo.reset(VertexBuffer::Create(this->cube_vertices, 48 * sizeof(float)));

				//Jotunn::BufferLayout layout =
				//{
				//	{ Jotunn::ShaderDataType::Float3, "position" }
				//};

				//this->vbo_layout = layout;

				//this->ibo.reset(IndexBuffer::Create(triangle_indices, sizeof(triangle_indices) / sizeof(uint32_t)));
			};

			float* ComputeSphereVertices(const int& num_subdivisions, int& num_vertices)
			{

			};

			//static void subdivide(std::vector<glm::vec3> positions, const int& num_indices, )

	};

	class SphereMeshGeomFactory : public MeshGeomFactory
	{
		public:

			SphereMeshGeomFactory() : MeshGeomFactory()
			{
				m_Geom = (std::shared_ptr<SphereMeshGeomFactory>(new SphereMeshGeomFactory));
			};

		private:
	};
}