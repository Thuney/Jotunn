#include "Mesh.h"
#include "Shader.h"

namespace Jotunn
{

	MeshGeometry::MeshGeometry(const std::shared_ptr<VertexArray>& vao, const std::shared_ptr<VertexBuffer>& vbo, const BufferLayout& vbo_layout, const std::shared_ptr<IndexBuffer>& ibo)
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

	//-------------------------------------------------------------------------

	MeshMaterial::MeshMaterial(const std::shared_ptr<std::vector<Uniform*>>& material_uniforms)
	{
		this->uniforms = material_uniforms;
	}

	MeshMaterial::~MeshMaterial()
	{
	}

	void MeshMaterial::Bind(Shader& shader)
	{
		if (this->uniforms != nullptr)
		{
			for (Uniform* u : *(this->uniforms))
			{
				shader.UploadUniform(*u);
			}
		}
	}

	//-------------------------------------------------------------------------

	Mesh::Mesh(MeshGeometry* geometry, MeshMaterial* material)
	{
		this->geometry = geometry;
		this->material = material;
	}

	Mesh::~Mesh()
	{
		delete this->geometry;
		delete this->material;
	}

	void Mesh::Bind(Shader& shader)
	{
		this->geometry->Bind();	
		this->material->Bind(shader);
	}
}