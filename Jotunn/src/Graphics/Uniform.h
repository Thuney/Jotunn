#pragma once

#include <string>

namespace Jotunn
{
	class Uniform
	{
		public:

			Uniform(const std::string& name)
			{

			}

			virtual void bind() = 0;

		private:

	};

	class IntUniform : Uniform
	{
		public:

			IntUniform(const std::string& name, const int value) : Uniform(name)
			{

			}

		private:

	};
}