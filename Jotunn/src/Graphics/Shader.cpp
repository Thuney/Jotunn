#include "Core/CoreInclude.h"

#include "Shader.h"
#include "Platform/Graphics/OpenGLShader.h"

namespace Jotunn
{
	std::shared_ptr<Shader> Shader::Create(const std::string& filepath)
	{
		return std::make_shared<OpenGLShader>(filepath);
	}

	std::shared_ptr<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
	}
}