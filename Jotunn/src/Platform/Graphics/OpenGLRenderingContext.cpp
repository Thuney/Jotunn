#include "OpenGLRenderingContext.h"

#include "Core/CoreInclude.h"

namespace Jotunn 
{

	OpenGLRenderingContext::OpenGLRenderingContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{

	}

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

	void OpenGLRenderingContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = glewInit();

	}

	void OpenGLRenderingContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}