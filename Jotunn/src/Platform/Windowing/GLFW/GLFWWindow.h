#pragma once

#include "Core/Engine/Window.h"
#include "Platform/Graphics/OpenGLRenderingContext.h"

namespace Jotunn
{
	/**
	 * A Window implementation using GLFW
	 */
	class GLFWWindow : public Window
	{

	public:
		GLFWWindow(const WindowProps& props);
		virtual ~GLFWWindow();

		/**
		 * Runs on Window update
		 */
		void OnUpdate() override;

		/**
		 * Returns the Window's width
		 */
		inline unsigned int GetWidth() const override { return m_Data.Width; }

		/**
		 * Returns the Window's height
		 */
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		/**
		 * Function to set the EventCallbackFn for this Window instance
		 * Generally called by parent Application
		 */
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

		/**
		 * Return the raw window type
		 */
		inline virtual void* GetNativeWindow() const { return m_Window; }

	private:
		/**
		 * Overridden base class function to initialize this Window instance
		 */
		virtual void Init(const WindowProps& props);

		/**
		 * Overridden base class function to shutdown this Window instance
		 */
		virtual void Shutdown();

		/**
		 * Raw window pointer
		 */
		GLFWwindow* m_Window;

		/**
		 * Stores information about this Window type
		 */
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFn EventCallback;
		};

		/**
		 * Stores information about this Window
		 */
		WindowData m_Data;

		OpenGLRenderingContext* context;
	};
}