#pragma once

namespace Jotunn
{
	class Shader
	{
		public:
			virtual ~Shader() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual const std::string& GetName() const = 0;

			static std::shared_ptr<Shader> Create(const std::string& filepath);
			static std::shared_ptr<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}