#include "GLFWWindow.h"

#include "Core/Event/ApplicationEvent.h"
#include "Core/Event/KeyEvent.h"
#include "Core/Event/MouseEvent.h"
#include "Core/CoreInclude.h"

namespace Jotunn
{
	/**
	 * Class member to track if the GLFW library is initialized
	 */
	static bool s_GLFWInitialized = false;

	/**
	 * Callback function for errors from GLFW
	 */
	static void GLFWErrorCallback(int error, const char* description)
	{

	}

	/**
	 * Definition for static function Window::Create()
	 * Returns a pointer to an instance of this Window type
	 */
	Window* Window::Create(const WindowProps& props)
	{
		JOTUNN_INFO("Created GLFW Window");

		return new GLFWWindow(props);
	}

	/**
	 * GLFWWindow Constructor
	 */
	GLFWWindow::GLFWWindow(const WindowProps& props)
	{
		Init(props);
	}
	
	/**
	 * GLFWWindow Destructor
	 */
	GLFWWindow::~GLFWWindow()
	{
		Shutdown();
	}

	/**
	 * Called on Window update
	 */
	void GLFWWindow::OnUpdate()
	{
		context->SwapBuffers();

		glfwPollEvents();
	}

	/**
	 * Initialization function for the Window
	 * Sets Window data, initializes GLFW, and sets callback functions
	 */
	void GLFWWindow::Init(const WindowProps& props)
	{
		//Window Data
		this->m_Data.Title = props.Title;
		this->m_Data.Width = props.Width;
		this->m_Data.Height = props.Height;

		//Handle GLFW initialization
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		//Create raw window instance
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);

		//Attach Window data to the raw window pointer
		glfwSetWindowUserPointer(m_Window, &m_Data);

		/**
		 * Set GLFW callbacks
	 	 */
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

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});

		context = new OpenGLRenderingContext(this->m_Window);
		context->Init();
	}

	/**
	 * Called when the Window is to be shut down
	 */
	void GLFWWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
		s_GLFWInitialized = false;
	}
}
