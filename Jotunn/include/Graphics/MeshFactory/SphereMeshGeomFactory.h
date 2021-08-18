#pragma once

#include "Graphics/Mesh.h"
#include "Graphics/MeshFactory/MeshGeomFactory.h"

#include <cmath>
#include "glm/gtc/type_ptr.hpp"

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

			int num_vertices;
			int num_elements;
			std::vector<glm::vec3> sphere_vertex_data;
			std::vector<uint32_t> sphere_indices;

			virtual void SetUpGeometry() override
			{
				ComputeSphere(5);

				float* vertex_data = (&sphere_vertex_data[0].x);
				uint32_t* indices = (&sphere_indices[0]);

				this->vao.reset(VertexArray::Create());
				this->vbo.reset(VertexBuffer::Create(vertex_data, 3 * sphere_vertex_data.size() * sizeof(float)));

				Jotunn::BufferLayout layout =
				{
					{ Jotunn::ShaderDataType::Float3, "position" }
				};

				this->vbo_layout = layout;
				this->ibo.reset(IndexBuffer::Create(indices, num_elements));
			};

			void ComputeSphere(const int& num_subdivisions)
			{

				int num_triangles = (int) (pow(4, (num_subdivisions + 1)));
				this->num_elements = 3 * num_triangles;

				int num_edges = (3 * num_triangles) / 2;
				this->num_vertices = 2 - num_triangles + num_edges;

				sphere_vertex_data.reserve(this->num_vertices);
				sphere_indices.reserve(this->num_elements);

				double negativeRootTwoOverThree = -(sqrt(2.0) / (3.0));
				const double negativeOneThird = -((1.0) / (3.0));
				double rootSixOverThree		  = (sqrt(6.0) / (3.0));

				sphere_vertex_data.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
				sphere_vertex_data.push_back(glm::vec3(0.0f, ((2.0f*sqrt(2.0f))/3.0f), negativeOneThird));
				sphere_vertex_data.push_back(glm::vec3(-rootSixOverThree, negativeRootTwoOverThree, negativeOneThird));
				sphere_vertex_data.push_back(glm::vec3(rootSixOverThree, negativeRootTwoOverThree, negativeOneThird));

				subdivide(sphere_vertex_data, sphere_indices, glm::vec3(0, 1, 2), num_subdivisions);
				subdivide(sphere_vertex_data, sphere_indices, glm::vec3(0, 2, 3), num_subdivisions);
				subdivide(sphere_vertex_data, sphere_indices, glm::vec3(0, 3, 1), num_subdivisions);
				subdivide(sphere_vertex_data, sphere_indices, glm::vec3(1, 3, 2), num_subdivisions);
			};

			static void subdivide(std::vector<glm::vec3>& positions, std::vector<uint32_t>& indices, const glm::vec3& triangle, int level)
			{
				if (level > 0)
				{
					positions.push_back(glm::normalize((0.5f)*(positions.at(triangle.x) + positions.at(triangle.y))));
					positions.push_back(glm::normalize((0.5f)*(positions.at(triangle.y) + positions.at(triangle.z))));
					positions.push_back(glm::normalize((0.5f)*(positions.at(triangle.z) + positions.at(triangle.x))));

					int i01 = positions.size() - 3;
					int i12 = positions.size() - 2;
					int i20 = positions.size() - 1;

					level--;

					subdivide(positions, indices, glm::vec3(triangle.x , i01, i20), level);
					subdivide(positions, indices, glm::vec3(i01, triangle.y, i12), level);
					subdivide(positions, indices, glm::vec3(i01, i12, i20), level);
					subdivide(positions, indices, glm::vec3(i20, i12, triangle.z), level);
				}
				else
				{
					indices.push_back(triangle.x);
					indices.push_back(triangle.y);
					indices.push_back(triangle.z);
				}
			};

	};

	class SphereMeshGeomFactory : public MeshGeomFactory
	{
		public:

			SphereMeshGeomFactory() : MeshGeomFactory()
			{
				m_Geom = (std::shared_ptr<SphereMeshGeometry>(new SphereMeshGeometry));
			};

		private:
	};
}