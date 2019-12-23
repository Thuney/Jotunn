#include "TestLayer.h"

#include "GL/glew.h"

TestLayer::TestLayer() : Layer("Test Layer"), m_CameraController(1280.0f / 720.0f, 0.1f, 50.0f)
{
}

void TestLayer::OnAttach()
{
	Jotunn::Renderer::Init();

	m_Shader = Jotunn::Shader::Create("SingleColor", "../res/vertex_shader.vert", "../res/fragment_shader.frag");

	float cube_vertices[48] =
	{
		-0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f, 1.0f, 0.5f, 1.0f, 0.0f, 0.0f,
		-0.5f, 1.0f, 0.5f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.0f, -0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f, 0.0f, -0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f, 1.0f, -0.5f, 1.0f, 0.0f, 0.0f,
		-0.5f, 1.0f, -0.5f, 1.0f, 0.0f, 0.0f,
	};

	std::shared_ptr<Jotunn::VertexArray> vertexArray;
	vertexArray.reset(Jotunn::VertexArray::Create());

	std::shared_ptr<Jotunn::VertexBuffer> vertexBuffer;
	vertexBuffer.reset(Jotunn::VertexBuffer::Create(cube_vertices, 48*sizeof(float)));
	Jotunn::BufferLayout layout =
	{
		{ Jotunn::ShaderDataType::Float3, "position" },
		{ Jotunn::ShaderDataType::Float3, "color" }
	};

	uint32_t triangle_indices[36] = { 
									  3, 0, 1, 3, 1, 2,
									  2, 1, 5, 2, 5, 6,
									  7, 3, 2, 7, 2, 6,
									  6, 5, 4, 6, 4, 7,
									  7, 4, 0, 7, 0, 3,
									  0, 4, 5, 0, 5, 1,
									};
	std::shared_ptr<Jotunn::IndexBuffer> indexBuffer;
	indexBuffer.reset(Jotunn::IndexBuffer::Create(triangle_indices, sizeof(triangle_indices) / sizeof(uint32_t)));

	m_BoxMesh.reset(new Jotunn::Mesh(new Jotunn::MeshGeometry(vertexArray, vertexBuffer, layout, indexBuffer), new Jotunn::MeshMaterial()));

}

void TestLayer::OnDetach()
{
		
}

void TestLayer::OnUpdate(Jotunn::Timestep ts)
{
	Jotunn::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Jotunn::RenderCommand::Clear();

	m_CameraController.OnUpdate(ts);

	Jotunn::Renderer::BeginScene(m_CameraController.GetCamera());

	Jotunn::Renderer::Submit(m_Shader, m_BoxMesh, glm::mat4(1.0f));

	Jotunn::Renderer::EndScene();
}

void TestLayer::OnImGuiRender()
{
		
}

void TestLayer::OnEvent(Jotunn::Event& e)
{
	m_CameraController.OnEvent(e);

	Jotunn::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Jotunn::MouseMovedEvent>([](Jotunn::MouseMovedEvent& e)
	{
		//JOTUNN_CORE_TRACE("Mouse Moved To Position ({0}, {1})", e.GetX(), e.GetY());
		return false;
	});
}