#include "Mesh.h"

namespace Jotunn
{
	MeshGeometry::MeshGeometry(std::shared_ptr<VertexArray> vao, std::shared_ptr<VertexBuffer> vbo, const BufferLayout& vbo_layout, std::shared_ptr<IndexBuffer> ibo)
	{
		this->vao = vao;
		this->vbo = vbo;
		this->vbo_layout = vbo_layout;
		this->ibo = ibo;

		SetUpGeometry();
	}

	MeshGeometry::~MeshGeometry()
	{

	}

	void MeshGeometry::Bind()
	{
		this->vao->Bind();
	}

	Mesh::Mesh(MeshGeometry* geometry, MeshMaterial* material)
	{
		this->geometry = geometry;
		this->material = material;
	}

	Mesh::~Mesh()
	{

	}

	void Mesh::Bind()
	{
		this->geometry->Bind();
	}
}