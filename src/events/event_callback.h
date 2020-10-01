#ifndef EVENT_CALLBACK_H
#define EVENT_CALLBACK_H

#include "event.h"

namespace Split
{

	class AEventCallback
	{
	public:
		virtual ~AEventCallback() {}
		void call(Event& event) { call_method(event); }

	protected:
		AEventCallback() {}

	private:
		virtual void call_method(Event& event) = 0;

	};

	template<class T, class E>
	class EventCallback : public AEventCallback
	{
	public:
		EventCallback(T* instance, void(T::* method)(E&)) : instance{ instance }, method{ method } {}
		~EventCallback() {}

	private:
		void call_method(Event& event) override { (instance->*method)(static_cast<E&>(event)); }

		T* instance;
		void(T::* method)(E&);
	};

}

#endif /* EVENT_CALLBACK_H */
