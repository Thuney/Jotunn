#include "TestLayer.h"

#include "GL/glew.h"

//Hardcoded strings for the very simple shaders required for drawing the white triangle

const GLchar* vertex_shader =
	"#version 150"										//Defines the GLSL version of this shader to be 1.50
	"\n"
	"in vec2 position;"									//Defines an input to the shader which is a 2-dimensional vector
	"\n"
	"void main()"
	"{"
	"	gl_Position = vec4(position, 0.0, 1.0);"		//Set the homogenous coordinates of the vertex given our 2D vector input
	"};";

const GLchar* fragment_shader =
	"#version 150"										//Defines the GLSL version of this shader to be 1.50
	"\n"
	"out vec4 outColor;"								//Defines an output to the shader which is a 4-dimensional vector
	"\n"
	"void main()"
	"{"
	"	outColor = vec4(1.0, 1.0, 1.0, 1.0);"			//Set the value of the (in this case constant and white) color output
	"}";

void TestLayer::OnAttach()
{
	m_Shader = Jotunn::Shader::Create("SingleColor", vertex_shader, fragment_shader);

	//Hardcoded array of our triangle vertices in (X, Y) pairs
	//Note that these values are in the range [-1.0, 1.0] to fit in
	//OpenGL's unprojected coordinate system
	triangle_vertices = new float[6]
	{
		//First Triangle
		0.0f, 0.5f,		//Vertex 1 (X, Y), top point
		0.5f, -0.5f,	//Vertex 2 (X, Y), bottom right point
		-0.5f, -0.5f,	//Vertex 3 (X, Y), bottom left point
	};

	m_VertexArray.reset(Jotunn::VertexArray::Create());	

	std::shared_ptr<Jotunn::VertexBuffer> vertexBuffer;
	vertexBuffer.reset(Jotunn::VertexBuffer::Create(triangle_vertices, 6*sizeof(float)));
	Jotunn::BufferLayout layout =
	{
		{ Jotunn::ShaderDataType::Float2, "position" }
	};
	vertexBuffer->SetLayout(layout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);
}

void TestLayer::OnDetach()
{
		
}

void TestLayer::OnUpdate(Jotunn::Timestep ts)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	m_Shader->Bind();

	m_VertexArray->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void TestLayer::OnImGuiRender()
{
		
}

void TestLayer::OnEvent(Jotunn::Event& event)
{
	Jotunn::EventDispatcher dispatcher(event);
	dispatcher.Dispatch<Jotunn::MouseMovedEvent>([](Jotunn::MouseMovedEvent& event)
	{
		JOTUNN_CORE_TRACE("Mouse Moved To Position ({0}, {1})", event.GetX(), event.GetY());
		return true;
	});
}