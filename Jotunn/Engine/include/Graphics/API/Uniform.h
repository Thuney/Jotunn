#pragma once

#include "Graphics/API/ShaderDataType.h"
#include "glm/glm.hpp"

#include <string>

namespace Jotunn
{

	class Uniform
	{
		public:

			Uniform(const std::string& name) : m_Name(name)
			{

			}

			std::string m_Name;
			ShaderDataType m_Type;

	};

	class Float3Uniform : public Uniform
	{
		public:

			Float3Uniform(const std::string& name, glm::vec3& value) : Uniform(name), m_Value(value)
			{
				this->m_Type = ShaderDataType::Float3;
			}

			glm::vec3& m_Value;

	};

}