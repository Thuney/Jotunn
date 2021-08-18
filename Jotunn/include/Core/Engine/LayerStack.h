#pragma once

#include "Core/CoreInclude.h"
#include "Core/Engine/Layer.h"

#include <vector>

namespace Jotunn 
{
	/**
	 * @brief Stores logical 'layers' of the rendering engine, with support for an overlay layer
	 * 
	 */
	class LayerStack
	{
		public:
			LayerStack();
			~LayerStack();

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);
			void PopLayer(Layer* layer);
			void PopOverlay(Layer* overlay);

			std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
			std::vector<Layer*>::iterator end() { return m_Layers.end(); }

		private:
			std::vector<Layer*> m_Layers;
			unsigned int m_LayerInsertIndex = 0;
	};
}