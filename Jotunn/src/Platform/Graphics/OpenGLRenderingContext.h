#pragma once

#include "Graphics/RenderingContext.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct GLFWwindow;

namespace Jotunn
{
	class OpenGLRenderingContext : public RenderingContext
	{

	public:
		OpenGLRenderingContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;

		GLuint vao;
		GLuint vbo;

		GLuint shaderProgram;

		//Hardcoded array of our triangle vertices in (X, Y) pairs
		//Note that these values are in the range [-1.0, 1.0] to fit in
		//OpenGL's unprojected coordinate system
		float* triangle_vertices;

	};
}