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

		template<class E> void postEvent(E& event)
		{
			Root::eventBus()->post(event);
		}

		template <class T, class E> void callbackSubscribe(void(T::* method)(E&))
		{
			Root::eventBus()->addCallback(static_cast<T*>(this), method);
		}

	private:
		virtual void eventBusSubscribe(void) {}
	};

	class EventBusListener
	{
	public:
		virtual ~EventBusListener() {}

	protected:

		template <class T, class E> void callbackSubscribe(void(T::* method)(E&))
		{
			Root::eventBus()->addCallback(static_cast<T*>(this), method);
		}

	private:
		virtual void eventBusSubscribe(void) {}
	};

}
