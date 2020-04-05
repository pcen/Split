#ifndef EVENT_BUS_CLIENT_H
#define EVENT_BUS_CLIENT_H

#include "pch.h"
#include "event_bus.h"
#include "app/root.h"

namespace Split
{

	class EventBusClient
	{
	public:
		virtual ~EventBusClient() {}

	protected:
		EventBusClient(void) {}

		template<class E> void post_event(E& event) { Root::event_bus()->post(event); }

		template <class T, class E> void callback_subscribe(void(T::* method)(E&))
		{
			Root::event_bus()->add_callback(static_cast<T*>(this), method);
		}

	private:
		virtual void event_bus_subscribe(void) = 0;
	};

}

#endif /* EVENT_BUS_CLIENT_H */
