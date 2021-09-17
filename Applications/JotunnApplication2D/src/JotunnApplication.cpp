#pragma once

#include "Jotunn.h"
#include "Core/Engine/EntryPoint.h"
#include "TestLayer.h"

class JotunnApplication2D : public Jotunn::Application
{

	public:
		JotunnApplication2D()
		{
			PushLayer(new TestLayer());	
		}

		~JotunnApplication2D()
		{

		}

};

Jotunn::Application* Jotunn::CreateApplication()
{
	return new JotunnApplication2D();
}