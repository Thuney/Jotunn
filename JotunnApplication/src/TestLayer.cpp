#include "TestLayer.h"

#include "GL/glew.h"

//Hardcoded strings for the very simple shaders required for drawing the triangle

const GLchar* vertex_shader =
	"#version 150"										//Defines the GLSL version of this shader to be 1.50
	"\n"
	"in vec3 position;"									//Defines an input to the shader which is a 2-dimensional vector
	"in vec3 color;"
	"\n"
	"out vec3 f_color;"
	"\n"
	"uniform mat4 u_ViewProjection;"
	"uniform mat4 u_Transform;"
	"\n"
	"void main()"
	"{"
	"	gl_Position = u_ViewProjection * u_Transform * vec4(position, 1.0);"		//Set the homogenous coordinates of the vertex given our 2D vector input
	"   f_color = color;"
	"};";

const GLchar* fragment_shader =
	"#version 150"										//Defines the GLSL version of this shader to be 1.50
	"\n"
	"in vec3 f_color;"
	"\n"
	"out vec4 outColor;"								//Defines an output to the shader which is a 4-dimensional vector
	"\n"
	"void main()"
	"{"
	"	outColor = vec4(f_color, 1.0);"					//Set the value of the color output
	"}";

TestLayer::TestLayer() : Layer("Test Layer"), m_CameraController(1280.0f / 720.0f, 0.1f, 50.0f)
{
}

void TestLayer::OnAttach()
{
	Jotunn::Renderer::Init();

	m_Shader = Jotunn::Shader::Create("SingleColor", vertex_shader, fragment_shader);

	float cube_vertices[48] =
	{
		-0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f,
		 0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f,
		 0.5f, 1.0f, 0.5f, 1.0f, 0.0f, 0.0f,
		-0.5f, 1.0f, 0.5f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.0f, -0.5f, 0.0f, 0.0f, 1.0f,
		 0.5f, 0.0f, -0.5f, 0.0f, 0.0f, 1.0f,
		 0.5f, 1.0f, -0.5f, 1.0f, 0.0f, 0.0f,
		-0.5f, 1.0f, -0.5f, 1.0f, 0.0f, 0.0f,
	};

	m_VertexArray.reset(Jotunn::VertexArray::Create());	

	std::shared_ptr<Jotunn::VertexBuffer> vertexBuffer;
	vertexBuffer.reset(Jotunn::VertexBuffer::Create(cube_vertices, 48*sizeof(float)));
	Jotunn::BufferLayout layout =
	{
		{ Jotunn::ShaderDataType::Float3, "position" },
		{ Jotunn::ShaderDataType::Float3, "color" }
	};
	vertexBuffer->SetLayout(layout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);

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
	m_VertexArray->SetIndexBuffer(indexBuffer);
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

	Jotunn::Renderer::Submit(m_Shader, m_VertexArray, glm::mat4(1.0f));

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