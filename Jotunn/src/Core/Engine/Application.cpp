#include "Application.h"

#include <functional>

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
	}

	/**
	 * Main loop for the engine
	 */
	void Application::Run()
	{
		while (m_Running)
		{
			//float time = (float)glfwGetTime();
			//float timestep = time - m_LastFrameTime;
			//m_LastFrameTime = time;

			m_Window->OnUpdate();
		}
	}

	/**
	 * Callback function for all window events
	 * Handles application events and propogates other events throughout the engine
	 */
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	}

	/**
	 * Callback function for a WindowCloseEvent
	 */
	bool Application::OnWindowClose(WindowCloseEvent & e)
	{
		m_Running = false;
		return true;
	}
}