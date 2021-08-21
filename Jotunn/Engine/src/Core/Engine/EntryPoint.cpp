#include "Core/Engine/EntryPoint.h"

int main(int argc, char** argv)
{
	Jotunn::Log::Init();
	JOTUNN_CORE_WARN("Initialized Log!");

	auto app = Jotunn::CreateApplication();
	app->Run();
	delete app;
}