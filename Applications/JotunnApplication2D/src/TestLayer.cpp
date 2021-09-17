#include "TestLayer.h"

#include "glm/gtc/type_ptr.hpp"

TestLayer::TestLayer() : Layer("Test Layer"), m_CameraController(1280.0f / 720.0f, 0.1f, 50.0f)
{
}

TestLayer::~TestLayer()
{

}

void TestLayer::OnAttach()
{
	Jotunn::Renderer::Init();
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

	Jotunn::Renderer::EndScene();
}

void TestLayer::OnImGuiRender()
{
	ImGui::Begin("Uniform Control");
	ImGui::ColorEdit3("Square Color", glm::value_ptr(color));
	ImGui::End();
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
