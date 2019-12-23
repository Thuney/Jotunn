#pragma once

#include "Core/Event/Event.h"
#include "Core/Engine/Timestep.h"

namespace Jotunn
{
	/**
	 * Holds information about a window
	 */
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Jotunn", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height)
		{
		}
	};

	/**
	 * Interface for Window types
	 */
	class Window
	{

		public:
			/**
			 * Typedef for an EventCallbackFn
			 * Wrapper around a function that takes a reference to an Event and returns void
			 */
			using EventCallbackFn = std::function<void(Event&)>;

			Window::Window()
			{

			}

			virtual ~Window() = default;

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			virtual float GetWindowTime() const = 0;

			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

			virtual void* GetNativeWindow() const = 0;

			/**
			 * Defined per platform
			 */
			static Window* Create(const WindowProps& props = WindowProps());
	};
}