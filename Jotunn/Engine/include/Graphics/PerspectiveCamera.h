#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

namespace Jotunn
{
	class PerspectiveCamera
	{
		public:
			PerspectiveCamera(const float aspect_ratio, const float nearPlane, const float farPlane, const glm::vec3 position, const glm::quat orientation);

			void SetProjection(const float aspect_ratio, const float nearPlane, const float farPlane);

			const glm::vec3& GetPosition() const { return m_Position; }
			void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }

			const glm::quat& GetOrientation() const { return m_Orientation; }
			void SetOrientation(const glm::quat& orientation) { m_Orientation = orientation; RecalculateViewMatrix(); }

			const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
			const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
			const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

			const glm::vec3 GetFront();
			const glm::vec3 GetLeft();
			const glm::vec3 GetUp();

		private:
			glm::mat4 m_ProjectionMatrix;
			glm::mat4 m_ViewMatrix;
			glm::mat4 m_ViewProjectionMatrix;

			glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
			glm::quat m_Orientation = glm::quat(glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

			void RecalculateViewMatrix();
	};
}
