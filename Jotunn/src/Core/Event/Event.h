#pragma once

#include "Core/CoreInclude.h"

namespace Jotunn
{

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

/**
 * Macro to define an event's type and name
 */
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

/**
 * Macro to define an event's categories
 */
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	/**
	 * Interface for an event
	 */
	class Event
	{

	public:
		/**
		 * Flag to signal if an event has already been handled elsewhere
		 */
		bool Handled = false;

		//Functions to get information about this event
		//Allow for polymorphic handling of events

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	};

	/**
	 * Dispatches events with provided functions
	 */
	class EventDispatcher
	{
		/**
		 * Typedef of an EventFn
		 * Wrapper around a function that takes a reference to an Event and returns a bool
		 */
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		/**
		 * Takes in a reference to an event and stores it in a member variable
		 */
		EventDispatcher(Event& event) : m_Event(event)
		{
		}

		/**
		 * Dispatches an event
		 * Compares the event type of the event instance to the type of the argument 
		 * in the provided function. If they are the same, calls the function with the 
		 * event instance
		 * 
		 * Returns true if the event types match, false otherwise
		 * The event is 'Handled' if the provided EventFn returns true
		 */
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		/**
		 * Reference to the Event being dispatched
		 */
		Event& m_Event;

	};

	/**
	 * Operator to quickly output an Event to an output stream
	 */
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
