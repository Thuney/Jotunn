#pragma once

#include "Graphics/API/Mesh.h"

#include <memory>

namespace Jotunn
{

	class MeshGeomFactory
	{
		public:

			MeshGeomFactory()
			{

			};

			std::shared_ptr<MeshGeometry> compute()
			{
				return m_Geom;
			};

		protected:

			std::shared_ptr<MeshGeometry> m_Geom;
	};
}