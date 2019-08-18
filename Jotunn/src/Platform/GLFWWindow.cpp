#include "GLFWWindow.h"

#include "../Core/Event/ApplicationEvent.h"

namespace Jotunn
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{

	}

	Window* Window::Create(const WindowProps& props)
	{
		return new GLFWWindow(props);
	}

	GLFWWindow::GLFWWindow(const WindowProps & props)
	{
		Init(props);
	}
		
	GLFWWindow::~GLFWWindow()
	{
		Shutdown();
	}

	void GLFWWindow::OnUpdate()
	{
		glfwPollEvents();
	}

	void GLFWWindow::Init(const WindowProps & props)
	{
		this->m_Data.Title = props.Title;
		this->m_Data.Width = props.Width;
		this->m_Data.Height = props.Height;

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);

		glfwSetWindowUserPointer(m_Window, &m_Data);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});
	}

	void GLFWWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
		s_GLFWInitialized = false;
	}
}
