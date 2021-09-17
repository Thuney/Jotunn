#pragma once

#include "Graphics/Render/RenderingContext.h"

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

	};
}