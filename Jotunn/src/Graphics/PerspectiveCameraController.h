#pragma once

#include "PerspectiveCamera.h"
#include "Core/Engine/Timestep.h"
#include "Core/Event/Event.h"
#include "Core/Event/MouseEvent.h"
#include "Core/Event/ApplicationEvent.h"
#include "Core/Event/KeyEvent.h"
#include "Core/Event/KeyCodes.h"

namespace Jotunn
{
	class PerspectiveCameraController
	{
		public:
			PerspectiveCameraController(float aspectRatio, const float nearPlane, const float farPlane, const glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 1.0f), const glm::quat orientation = glm::quat(glm::vec3(glm::radians(0.0f), glm::radians(0.0f), glm::radians(0.0f))));

			void OnUpdate(Timestep ts);
			void OnEvent(Event& e);

			PerspectiveCamera& GetCamera() { return m_Camera; }
			const PerspectiveCamera& GetCamera() const { return m_Camera; }

		private:
			bool OnWindowResized(WindowResizeEvent& e);
			bool OnMouseMoved(MouseMovedEvent& e);
			bool OnKeyPressed(KeyPressedEvent& e);

		private:
			float m_AspectRatio;
			float m_NearPlane;
			float m_FarPlane;
			PerspectiveCamera m_Camera;

			glm::vec3 m_CameraPosition;
			glm::quat m_Orientation;
			float m_CameraTranslationSpeed = 4.0f;
	};
}