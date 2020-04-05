#ifndef EVENT_BUS_CLIENT_H
#define EVENT_BUS_CLIENT_H

#include "pch.h"
#include "event_bus.h"

namespace Split
{

	class EventBusClient
	{
	public:
		virtual ~EventBusClient() {}

	protected:
		EventBusClient(EventBus* event_bus) : event_bus{ event_bus } {}
		EventBusClient(void) : event_bus{ nullptr } {}

		template<class E> void post_event(E& event) { event_bus->post(event); }

		/* Some derived class constructors have no knowledge of EventBus
		 */
		void set_event_bus(EventBus* bus)
		{
			if (!event_bus)
				event_bus = bus;
		}

		template <class T, class E> void callback_subscribe(void(T::* method)(E&))
		{
			event_bus->add_callback(static_cast<T*>(this), method);
		}

	private:
		virtual void event_bus_subscribe(void) = 0;
		EventBus* event_bus;
	};

}

#endif /* EVENT_BUS_CLIENT_H */
