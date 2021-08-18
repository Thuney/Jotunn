#pragma once

#include "Jotunn.h"
#include "Core/Engine/EntryPoint.h"
#include "TestLayer.h"

class JotunnApplication : public Jotunn::Application
{

	public:
		JotunnApplication()
		{
			PushLayer(new TestLayer());	
		}

		~JotunnApplication()
		{

		}

};

Jotunn::Application* Jotunn::CreateApplication()
{
	return new JotunnApplication();
}