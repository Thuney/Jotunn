#pragma once

#include "Graphics/Uniform.h"

namespace Jotunn
{
	class Shader
	{
		public:
			virtual ~Shader() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual const std::string& GetName() const = 0;

			virtual void UploadUniform(const Uniform& uniform) = 0;

			static std::shared_ptr<Shader> Create(const std::string& name, const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath);
	};
}