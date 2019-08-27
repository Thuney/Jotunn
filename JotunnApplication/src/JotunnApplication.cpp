#include "Jotunn.h"

class JotunnApplication : public Jotunn::Application
{

public:
	JotunnApplication()
	{
		
	}

	~JotunnApplication()
	{

	}

};

Jotunn::Application* Jotunn::CreateApplication()
{
	return new JotunnApplication();
}