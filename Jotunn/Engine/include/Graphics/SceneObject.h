#pragma once

#include <string>
#include <vector>

#include "Graphics/Mesh.h"

namespace Jotunn
{

	class SceneObject
	{
		public:

			SceneObject(const std::string& name) : m_Name(name)
			{

			}
			~SceneObject()
			{

			}

			std::string m_Name;

		private:

			std::vector<Mesh> m_Meshes;

	};

}