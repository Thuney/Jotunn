#include "Application.h"

namespace Jotunn
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			//float time = (float)glfwGetTime();
			//float timestep = time - m_LastFrameTime;
			//m_LastFrameTime = time;


		}
	}
}