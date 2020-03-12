#include "PerspectiveCameraController.h"

#include "Core/Engine/Input.h"

namespace Jotunn
{
	PerspectiveCameraController::PerspectiveCameraController(float aspectRatio, const float nearPlane, const float farPlane, const glm::vec3 cameraPosition, const glm::quat orientation) : m_AspectRatio(aspectRatio), m_NearPlane(nearPlane), m_FarPlane(farPlane), m_CameraPosition(cameraPosition), m_Orientation(orientation), m_Camera(m_AspectRatio, m_NearPlane, m_FarPlane, m_CameraPosition, m_Orientation)
	{
		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetOrientation(m_Orientation);
	}

	void PerspectiveCameraController::OnUpdate(Timestep ts)
	{
		if (Input::IsKeyPressed(JOTUNN_KEY_W))
		{
			m_CameraPosition -= m_Camera.GetFront() * m_CameraTranslationSpeed * ts.GetSeconds();
			m_Camera.SetPosition(m_CameraPosition);
		}

		if (Input::IsKeyPressed(JOTUNN_KEY_A))
		{
			m_CameraPosition -= m_Camera.GetLeft() * m_CameraTranslationSpeed * ts.GetSeconds();
			m_Camera.SetPosition(m_CameraPosition);
		}

		if (Input::IsKeyPressed(JOTUNN_KEY_S))
		{
			m_CameraPosition += m_Camera.GetFront() * m_CameraTranslationSpeed * ts.GetSeconds();
			m_Camera.SetPosition(m_CameraPosition);
		}

		if (Input::IsKeyPressed(JOTUNN_KEY_D))
		{
			m_CameraPosition += m_Camera.GetLeft() * m_CameraTranslationSpeed * ts.GetSeconds();
			m_Camera.SetPosition(m_CameraPosition);
		}

		if (Input::IsKeyPressed(JOTUNN_KEY_Q))
		{
			glm::quat key_roll_quat = glm::quat(glm::vec3(0.0f, 0.0f, 0.1f));

			m_Orientation = key_roll_quat * m_Orientation;
			m_Camera.SetOrientation(m_Orientation);
		}

		if (Input::IsKeyPressed(JOTUNN_KEY_E))
		{
			glm::quat key_roll_quat = glm::quat(glm::vec3(0.0f, 0.0f, -0.1f));

			m_Orientation = key_roll_quat * m_Orientation;
			m_Camera.SetOrientation(m_Orientation);
		}
	}

	void PerspectiveCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<Jotunn::WindowResizeEvent>(JOTUNN_BIND_EVENT_FN(PerspectiveCameraController::OnWindowResized));
		dispatcher.Dispatch<Jotunn::MouseMovedEvent>(JOTUNN_BIND_EVENT_FN(PerspectiveCameraController::OnMouseMoved));
		dispatcher.Dispatch<Jotunn::KeyPressedEvent>(JOTUNN_BIND_EVENT_FN(PerspectiveCameraController::OnKeyPressed));
	}

	bool PerspectiveCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		m_Camera.SetProjection(((float)e.GetWidth() / (float)e.GetHeight()), 0.1f, 50.0f);

		JOTUNN_CORE_TRACE("Window Resize Event with proportions : ({0}, {1})", (float)e.GetWidth(), (float)e.GetHeight());

		return true;
	}

	bool PerspectiveCameraController::OnMouseMoved(MouseMovedEvent& e)
	{
		static glm::vec2 previous_mouse_position(e.GetX(), e.GetY());
		static const float mouseX_Sensitivity = 0.02f;
		static const float mouseY_Sensitivity = 0.02f;

		//Right Mouse Button
		if (Input::IsMouseButtonPressed(1))
		{
			glm::vec2 mouse_delta = glm::vec2(e.GetX(), e.GetY()) - previous_mouse_position;

			float key_yaw = mouseX_Sensitivity * mouse_delta.x;
			float key_pitch = mouseY_Sensitivity * mouse_delta.y;

			glm::quat key_pitch_quat = glm::quat(glm::vec3(key_pitch, 0.0f, 0.0f));
			glm::quat key_yaw_quat = glm::quat(glm::vec3(0.0f, key_yaw, 0.0f));

			m_Orientation = key_pitch_quat * m_Orientation * key_yaw_quat;

			m_Camera.SetOrientation(m_Orientation);
		}

		previous_mouse_position.x = e.GetX();
		previous_mouse_position.y = e.GetY();

		return true;
	}

	bool PerspectiveCameraController::OnKeyPressed(KeyPressedEvent& e)
	{
		return true;
	}
}
