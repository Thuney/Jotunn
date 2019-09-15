#pragma once

#include "Core/Engine/Layer.h"
#include "Core/Event/MouseEvent.h"

class TestLayer : public Jotunn::Layer
{

	public:

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate(Jotunn::Timestep ts) override;
		void OnImGuiRender() override;
		void OnEvent(Jotunn::Event& event) override;

};