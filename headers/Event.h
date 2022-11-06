#ifndef EVENT_H
#define EVENT_H

#include "ppch.h"
#include "Core.h"

namespace Pandemonium {
	enum class EventType {
		None = 0,
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowFocusLost,
		WindowMoved,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		KeyTyped,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory {
		None					 = 0,
		EventCategoryApplication = 1 << 0,
		EventCategoryInput		 = 1 << 1,
		EventCategoryKeyboard	 = 1 << 2,
		EventCategoryMouse		 = 1 << 3,
		EventCategoryMouseButton = 1 << 4
	};

	class PANDEMONIUM_API Event {
	public:
		virtual ~Event()							 = default;

		virtual EventType	GetEventType() const	 = 0;
		virtual const char* GetName() const			 = 0;
		virtual int			GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool			IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

		bool				Handled = false;
	};

	class EventDispatcher {
		// template <typename T> using EventFn = std::function<bool>(T&);
	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template <typename T, typename F> bool Dispatch(const F& func) {
			if(m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.ToString(); }
} // namespace Pandemonium

#endif /* EVENT_H */