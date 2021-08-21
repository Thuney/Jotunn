#pragma once

#include "Core/Event/Event.h"
#include "Core/Event/ApplicationEvent.h"
#include "Core/Event/MouseEvent.h"

#include "Core/Engine/Window.h"
#include "Core/Engine/LayerStack.h"
#include "Core/Engine/ImGuiLayer.h"

namespace Jotunn
{
	/**
	 *	Interface for an application making use of the Jotunn rendering engine
	 */
	class Application
	{
		public:

			Application();
			virtual ~Application() = default;

			/**
			 * The main loop of the application
			 */
			void Run();

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			/**
			 * Event callback function
			 * Processes application events and propogates others through the rest of the engine
			 */
			void OnEvent(Event& e);

			/**
			 * Returns a reference to the application's window instance
			 */
			inline Window& GetWindow() { return *m_Window; }

			/**
			 * Return a reference to this application
			 */
			inline static Application& Get() { return *s_Instance; }

		private:
			/**
			 * Unique pointer to the application's window instance
			 */
			std::unique_ptr<Window> m_Window;

			ImGuiLayer* m_ImGuiLayer;

			LayerStack m_LayerStack;

			/**
			 * Flag variable to signal if the application is running or not
			 */
			bool m_Running = true;

			/**
			 * Stores the window time of the last frame
			 * Used for calculating the delta between frames
			 */
			Timestep m_LastFrameTime = Timestep(0.0f);

			/**
			 * Class pointer to the current application
			 */
			static Application* s_Instance;

			/**
			 * Callback function to execute on a WindowCloseEvent
			 */
			bool OnWindowClose(WindowCloseEvent& e);
	};

	/**
	 * Returns an instance of an application
	 * To be defined in the client
	 */
	Application* CreateApplication();

}