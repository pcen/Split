#pragma once

#include "pch.h"
#include "EventBus.h"
#include "core/root.h"

namespace Split
{

	class EventBusClient
	{
	public:
		virtual ~EventBusClient() {}

	protected:
		EventBusClient() {}

		template<class E> void post_event(E& event)
		{
			Root::event_bus()->post(event);
		}

		template <class T, class E> void callback_subscribe(void(T::* method)(E&))
		{
			Root::eventBus()->addCallback(static_cast<T*>(this), method);
		}

	private:
		virtual void event_bus_subscribe(void) {}
	};

	class EventBusListener
	{
	public:
		virtual ~EventBusListener() {}

	protected:
		EventBusListener() {}

		template <class T, class E> void callback_subscribe(void(T::* method)(E&))
		{
			Root::eventBus()->addCallback(static_cast<T*>(this), method);
		}

	private:
		virtual void event_bus_subscribe(void) {}
	};

}
