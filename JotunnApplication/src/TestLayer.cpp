#include "TestLayer.h"

void TestLayer::OnAttach()
{

}

void TestLayer::OnDetach()
{
		
}

void TestLayer::OnUpdate(Jotunn::Timestep ts)
{

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