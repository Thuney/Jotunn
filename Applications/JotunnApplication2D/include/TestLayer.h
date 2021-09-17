#pragma once

#include "Jotunn.h"

class TestLayer : public Jotunn::Layer
{
	public:

		TestLayer();
		~TestLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate(Jotunn::Timestep ts) override;
		void OnImGuiRender() override;
		void OnEvent(Jotunn::Event& event) override;

	private:

		glm::vec3 color;

		Jotunn::PerspectiveCameraController m_CameraController;
};
