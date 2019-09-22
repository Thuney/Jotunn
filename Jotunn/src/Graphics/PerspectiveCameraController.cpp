#include "PerspectiveCameraController.h"

namespace Jotunn
{
	PerspectiveCameraController::PerspectiveCameraController(float aspectRatio, const float nearPlane, const float farPlane, const glm::vec3 cameraPosition, const glm::quat orientation) : m_AspectRatio(aspectRatio), m_NearPlane(nearPlane), m_FarPlane(farPlane), m_CameraPosition(cameraPosition), m_Orientation(orientation), m_Camera(m_AspectRatio, m_NearPlane, m_FarPlane, m_CameraPosition, m_Orientation)
	{
	}

	void PerspectiveCameraController::OnUpdate(Timestep ts)
	{
	}

	void PerspectiveCameraController::OnEvent(Event & e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<Jotunn::WindowResizeEvent>(JOTUNN_BIND_EVENT_FN(PerspectiveCameraController::OnWindowResized));
		dispatcher.Dispatch<Jotunn::MouseMovedEvent>(JOTUNN_BIND_EVENT_FN(PerspectiveCameraController::OnMouseMoved));
		dispatcher.Dispatch<Jotunn::KeyPressedEvent>(JOTUNN_BIND_EVENT_FN(PerspectiveCameraController::OnKeyPressed));
	}

	bool PerspectiveCameraController::OnWindowResized(WindowResizeEvent & e)
	{
		return false;
	}

	bool PerspectiveCameraController::OnMouseMoved(MouseMovedEvent & e)
	{
		static glm::vec2 previous_mouse_position(e.GetX(), e.GetY());

		glm::vec2 mouse_delta = glm::vec2(e.GetX(), e.GetY()) - previous_mouse_position;

		previous_mouse_position.x = e.GetX();
		previous_mouse_position.y = e.GetY();

		const float mouseX_Sensitivity = 0.02f;
		const float mouseY_Sensitivity = 0.02f;

		float key_yaw = mouseX_Sensitivity * mouse_delta.x;
		float key_pitch = mouseY_Sensitivity * mouse_delta.y;

		glm::quat key_quat = glm::quat(glm::vec3(key_pitch, key_yaw, 0.0f));
		m_Orientation = key_quat * m_Orientation;
		
		m_Camera.SetOrientation(m_Orientation);

		return true;
	}

	bool PerspectiveCameraController::OnKeyPressed(KeyPressedEvent& e)
	{
		switch(e.GetKeyCode())
		{
			case JOTUNN_KEY_W:
				m_CameraPosition.z += m_CameraTranslationSpeed;
				break;
			case JOTUNN_KEY_A:
				m_CameraPosition.x += m_CameraTranslationSpeed;
				break;
			case JOTUNN_KEY_S:
				m_CameraPosition.z -= m_CameraTranslationSpeed;
				break;
			case JOTUNN_KEY_D:
				m_CameraPosition.x -= m_CameraTranslationSpeed;
				break;
			default:
				break;
		}

		m_Camera.SetPosition(m_CameraPosition);

		return true;
	}
}