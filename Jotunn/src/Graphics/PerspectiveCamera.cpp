#include "PerspectiveCamera.h"

namespace Jotunn
{
	PerspectiveCamera::PerspectiveCamera(const float aspect_ratio, const float nearPlane, const float farPlane, const glm::vec3 position, const glm::quat orientation) : m_ProjectionMatrix(glm::perspective(glm::radians(45.0f), aspect_ratio, nearPlane, farPlane)), m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void PerspectiveCamera::SetProjection(const float aspect_ratio, const float nearPlane, const float farPlane)
	{
		m_ProjectionMatrix = glm::perspective(glm::radians(45.0f), aspect_ratio, nearPlane, farPlane);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	const glm::vec3& PerspectiveCamera::GetFront()
	{
		m_Orientation = glm::normalize(m_Orientation);
		glm::mat4 rotate = glm::mat4_cast(m_Orientation);

		return glm::vec3(0.0f, 0.0f, -1.0f) * m_Orientation;
	}

	const glm::vec3 & PerspectiveCamera::GetLeft()
	{
		m_Orientation = glm::normalize(m_Orientation);
		glm::mat4 rotate = glm::mat4_cast(m_Orientation);

		return glm::vec3(-1.0f, 0.0f, 0.0f) * m_Orientation;
	}

	void PerspectiveCamera::RecalculateViewMatrix()
	{
		m_Orientation = glm::normalize(m_Orientation);
		glm::mat4 rotate = glm::mat4_cast(m_Orientation);

		glm::mat4 translate = glm::mat4(1.0f);
		translate = glm::translate(translate, m_Position);

		m_ViewMatrix = rotate * translate;
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}