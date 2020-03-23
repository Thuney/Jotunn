#include "TestLayer.h"

#include "glm/gtc/type_ptr.hpp"

#include "Graphics/MeshFactory/CubeMeshGeomFactory.h"
#include "Graphics/MeshFactory/SphereMeshGeomFactory.h"

TestLayer::TestLayer() : Layer("Test Layer"), m_CameraController(1280.0f / 720.0f, 0.1f, 50.0f)
{
}

TestLayer::~TestLayer()
{

}

void TestLayer::OnAttach()
{
	Jotunn::Renderer::Init();

	color = glm::vec3(0.0f, 1.0f, 0.0f);

	m_Shader = Jotunn::Shader::Create("SingleColor", "../res/vertex_shader.vert", "../res/fragment_shader.frag");

	std::unique_ptr<std::vector<Jotunn::Uniform*>> material_uniforms;
	material_uniforms.reset(new std::vector<Jotunn::Uniform*>);
	material_uniforms->push_back(new Jotunn::Float3Uniform("u_Color", color));

	color_material = std::shared_ptr<Jotunn::MeshMaterial>(new Jotunn::MeshMaterial(material_uniforms));

	Jotunn::CubeMeshGeomFactory cube_factory;
	Jotunn::SphereMeshGeomFactory sphere_factory;
	sphere_geom = sphere_factory.compute();
	cube_geom = cube_factory.compute();

	m_BoxMesh.reset(new Jotunn::Mesh(cube_geom, color_material));
	m_SphereMesh.reset(new Jotunn::Mesh(sphere_geom, color_material));

}

void TestLayer::OnDetach()
{
		
}

void TestLayer::OnUpdate(Jotunn::Timestep ts)
{
	Jotunn::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Jotunn::RenderCommand::Clear();

	m_CameraController.OnUpdate(ts);

	Jotunn::Renderer::BeginScene(m_CameraController.GetCamera());

	Jotunn::Renderer::Submit(m_Shader, m_BoxMesh, glm::mat4(1.0f));
	Jotunn::Renderer::Submit(m_Shader, m_SphereMesh, glm::mat4(1.0f));

	Jotunn::Renderer::EndScene();
}

void TestLayer::OnImGuiRender()
{
	ImGui::Begin("Uniform Control");
	ImGui::ColorEdit3("Square Color", glm::value_ptr(color));
	ImGui::End();
}

void TestLayer::OnEvent(Jotunn::Event& e)
{
	m_CameraController.OnEvent(e);

	Jotunn::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Jotunn::MouseMovedEvent>([](Jotunn::MouseMovedEvent& e)
	{
		//JOTUNN_CORE_TRACE("Mouse Moved To Position ({0}, {1})", e.GetX(), e.GetY());
		return false;
	});


}
