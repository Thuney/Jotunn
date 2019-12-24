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

}