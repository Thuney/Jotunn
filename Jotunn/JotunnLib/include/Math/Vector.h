#pragma once

#include <string>

namespace Jotunn
{

	class Vector2D
	{
		public:

			float x = 0.0f;
			float y = 0.0f;
			
			Vector2D() { };
			Vector2D(float x, float y)
			{
				this->x = x;
				this->y = y;
			}
			~Vector2D() { };

			std::string ToString()
			{
				return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
			}

		private:

	};

	class Vector3D
	{
		public:

			float x = 0.0f;
			float y = 0.0f;
			float z = 0.0f;

			Vector3D() { };
			Vector3D(float x, float y, float z)
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}
			~Vector3D() { };

			std::string ToString()
			{
				return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")";
			}

		private:

	};

}