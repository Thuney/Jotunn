#pragma once

#include "Core/Engine/Layer.h"
#include "Core/Event/Event.h"
#include "Core/Event/MouseEvent.h"
#include "Graphics/Renderer.h"
#include "Graphics/PerspectiveCameraController.h"
#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"

class TestLayer : public Jotunn::Layer
{
	public:

		TestLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate(Jotunn::Timestep ts) override;
		void OnImGuiRender() override;
		void OnEvent(Jotunn::Event& event) override;

	private:
		Jotunn::PerspectiveCameraController m_CameraController;

		std::shared_ptr<Jotunn::Shader> m_Shader = nullptr;
		std::shared_ptr<Jotunn::VertexArray> m_VertexArray = nullptr;

		//Hardcoded array of our triangle vertices in (X, Y) pairs
		//Note that these values are in the range [-1.0, 1.0] to fit in
		//OpenGL's unprojected coordinate system
		float* triangle_vertex_data;
};