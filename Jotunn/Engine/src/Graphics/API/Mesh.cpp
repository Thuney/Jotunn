#include "Graphics/API/Mesh.h"
#include "Graphics/API/Shader.h"

namespace Jotunn
{

	MeshGeometry::MeshGeometry(std::unique_ptr<VertexArray>& vao, std::shared_ptr<VertexBuffer> vbo, const BufferLayout& vbo_layout, std::shared_ptr<IndexBuffer> ibo)
	{
		this->vao.reset(nullptr);
		this->vao.swap(vao);
		this->vbo = vbo;
		this->vbo_layout = vbo_layout;
		this->ibo = ibo;

		SetUpGraphics();
	}

	MeshGeometry::MeshGeometry()
	{

	}

	MeshGeometry::~MeshGeometry()
	{

	}

	void MeshGeometry::Bind()
	{
		this->vao->Bind();
	}

	void MeshGeometry::SetUpGeometry()
	{
		this->vao.reset(VertexArray::Create());
		this->vbo.reset(VertexBuffer::Create(nullptr, 0));

		this->ibo = nullptr;
	};
	 
	void MeshGeometry::SetUpGraphics()
	{
		this->vbo->SetLayout(this->vbo_layout);
		this->vao->AddVertexBuffer(this->vbo);
		this->vao->SetIndexBuffer(this->ibo);

		JOTUNN_CORE_TRACE("Graphics Set Up");
	}

	//-------------------------------------------------------------------------

	MeshMaterial::MeshMaterial(std::unique_ptr<std::vector<Uniform*>>& material_uniforms)
	{
		this->uniforms.reset(nullptr);
		this->uniforms.swap(material_uniforms);
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
				if(u != nullptr)
					shader.UploadUniform(*u);
			}
		}
	}

	//-------------------------------------------------------------------------

	Mesh::Mesh(std::shared_ptr<MeshGeometry> geometry, std::shared_ptr<MeshMaterial> material)
	{
		this->geometry = geometry;
		this->material = material;
	}

	Mesh::~Mesh()
	{

	}

	void Mesh::Bind(Shader& shader)
	{
		this->geometry->Bind();	
		this->material->Bind(shader);
	}
}