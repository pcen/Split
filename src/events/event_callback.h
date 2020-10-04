#pragma once

#include "event.h"

namespace Split
{

	class EventCallback
	{
	public:
		virtual ~EventCallback() {}
		void call(Event& event) { invoke(event); }

	private:
		virtual void invoke(Event& event) = 0;
	};

	template<class T, class E>
	class Callback : public EventCallback
	{
	public:
		Callback(T* instance, void(T::* method)(E&))
			: instance{ instance },
			method{ method } {}

	private:
		void invoke(Event& event) override
		{
			(instance->*method)(static_cast<E&>(event));
		}

		T* instance;
		void(T::* method)(E&);
	};

}
