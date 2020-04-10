#ifndef EVENT_H
#define EVENT_H

#include "pch.h"

/* Static and instance methods to get event_type of event
 */
#define EVENT_TYPE_METHODS(type_name)                                   \
event_type type(void) const override { return static_type(); }      \
static event_type static_type(void) { return event_type::##type_name; } \
static std::string get_name(void) { return event_name(static_type()); }

namespace Split
{

	enum class event_type
	{
		GENERIC = 0, WINDOW_CLOSE = 1, WINDOW_RESIZE = 2,
		KEY_PRESS = 3, KEY_RELEASE = 4,
		MOUSE_PRESS = 5, MOUSE_RELEASE = 6, MOUSE_MOVE = 7, MOUSE_SCROLL = 8
	};

	static const std::string event_names[10] =
	{
		"GENERIC", "WINDOW_CLOSE", "WINDOW_RESIZE",
		"KEY_PRESS", "KEY_RELEASE", "KEY_REPEAT",
		"MOUSE_PRESS", "MOUSE_RELEASE", "MOUSE_MOVE", "MOUSE_SCROLL"
	};

	inline const std::string& event_name(event_type type)
	{
		return event_names[(int)type];
	}

	class Event
	{
	public:
		virtual ~Event() {}

		virtual inline std::string str(void) const = 0;
		virtual event_type type(void) const = 0;
		static event_type static_type(void) { return event_type::GENERIC; }
		static std::string get_name(void) { return event_name(static_type()); }

	protected:
		Event() {}
	};

	inline std::ostream& operator << (std::ostream& stream, const Event& event)
	{
		return stream << event.str();
	}

}

#endif /* EVENT_H */
