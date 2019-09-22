#pragma once

#include "Core/Engine/Layer.h"

#include "Core/Event/ApplicationEvent.h"
#include "Core/Event/KeyEvent.h"
#include "Core/Event/MouseEvent.h"

namespace Jotunn
{
	/**
	 * @brief Application Layer to handle rendering of ImGui 2D GUI elements
	 * 
	 */
	class ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer() = default;

			virtual void OnAttach() override;
			virtual void OnDetach() override;
			virtual void OnImGuiRender() override;

			void Begin();
			void End();
	};

}