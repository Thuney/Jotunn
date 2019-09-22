#pragma once

#include "Core/CoreInclude.h"

namespace Jotunn
{
	/**
	 * @brief Provides a general interface for obtaining input independent of platform. 
	 * Stores a static instance of the current platform's input object.
	 */
	class Input
	{
		public:
			//Keycodes found in Core/Event/KeyCodes.h
			inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

			inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
			inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
			inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
			inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

		protected:
			virtual bool IsKeyPressedImpl(int keycode) = 0;

			virtual bool IsMouseButtonPressedImpl(int button) = 0;
			virtual std::pair<float, float> GetMousePositionImpl() = 0;
			virtual float GetMouseXImpl() = 0;
			virtual float GetMouseYImpl() = 0;

		private:

			/**
			 * @brief Static instance of the current platform's input object.
			 * Constructed in platform-specific derived class.
			 */
			static Input* s_Instance;
	};

}