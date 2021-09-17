#include "Graphics/Render/RenderCommand.h"
#include "Graphics/Render/RendererAPI.h"
#include "Platform/Graphics/OpenGLRendererAPI.h"

namespace Jotunn
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}