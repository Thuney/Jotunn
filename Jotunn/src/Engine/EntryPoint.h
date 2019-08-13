#pragma once

extern Jotunn::Application* Jotunn::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Jotunn::CreateApplication();
	app->Run();
	delete app;
}