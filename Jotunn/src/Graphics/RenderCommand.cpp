#include "RenderCommand.h"
#include "Graphics/RendererAPI.h"
#include "Platform/Graphics/OpenGLRendererAPI.h"

namespace Jotunn
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}