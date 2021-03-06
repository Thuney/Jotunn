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

		std::shared_ptr<Jotunn::Shader> m_Shader = nullptr;

		std::shared_ptr<Jotunn::MeshMaterial> color_material = nullptr;
		std::shared_ptr<Jotunn::MeshGeometry> cube_geom = nullptr;
		std::shared_ptr<Jotunn::MeshGeometry> sphere_geom = nullptr;
		std::unique_ptr<Jotunn::Mesh> m_BoxMesh  = nullptr;
		std::unique_ptr<Jotunn::Mesh> m_SphereMesh = nullptr;
		//std::shared_ptr<Jotunn::VertexArray> m_VertexArray = nullptr;

		//Hardcoded array of our triangle vertices in (X, Y) pairs
		//Note that these values are in the range [-1.0, 1.0] to fit in
		//OpenGL's unprojected coordinate system
		float* cube_vertices;
};
