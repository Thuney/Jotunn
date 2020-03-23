#pragma once

#include <string>

namespace Jotunn
{

	class Scene
	{
		public:

			Scene(const std::string& title) : m_Title(title)
			{

			}
			~Scene()
			{

			}

			std::string m_Title;

		private:

	};

}