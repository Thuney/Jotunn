#pragma once

#include "Core/CoreInclude.h"
#include "Timestep.h"
#include "Core/Event/Event.h"

namespace Jotunn
{
	/**
	 * @brief Logical 'Layer' for our rendering engine
	 * Ordered in a LayerStack object by the Application
	 * Updates, Renders ImGui elements, and handles events independently
	 */	
	class Layer
	{
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer() = default;

			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate(Timestep ts) {}
			virtual void OnImGuiRender() {}
			virtual void OnEvent(Event& event) {}

			inline const std::string& GetName() const { return m_DebugName; }

		protected:
			std::string m_DebugName;
	};
}