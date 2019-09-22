#include "Application.h"

#include "Core/CoreInclude.h"

#include "Core/Event/MouseEvent.h"

//#include "Graphics/Renderer.h"

namespace Jotunn
{
	/**
	 * Macro to bind an Application function so it may be passed as an argument to an event dispatch function
	 */
	#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	/**
	 * First instantiation of the class pointer to the current application instance
	 */
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		/**
		 * Set reference to the current instance
		 */
		s_Instance = this;

		/**
		 * Create the window instance for this application
		 * Window::Create() is defined per platform
		 */
		m_Window = std::unique_ptr<Window>(Window::Create());

		/**
		 * Set the member function OnEvent as the callback for all events from the window
		 */
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		//Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	/**
	 * Main loop for the engine
	 */
	void Application::Run()
	{
		while (m_Running)
		{
			float current_time = m_Window->GetWindowTime();
			Timestep delta_time(current_time - m_LastFrameTime);
			m_LastFrameTime = current_time;

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(delta_time);

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer * layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer * layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	/**
	 * Callback function for all window events
	 * Handles application events and propogates other events throughout the engine
	 */
	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(event);
			if (event.Handled)
				break;
		}
	}

	/**
	 * Callback function for a WindowCloseEvent
	 */
	bool Application::OnWindowClose(WindowCloseEvent & e)
	{
		JOTUNN_CORE_TRACE("Window Closed Event Triggered");
		m_Running = false;
		return true;
	}
}