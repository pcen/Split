#pragma once

#include "event_callback.h"

namespace Split
{

	class EventBusRegistry
	{
	public:
		typedef std::unordered_map<event_type, EventCallback*> callback_map;

		EventBusRegistry();
		~EventBusRegistry();

		bool hasUser(void* user);
		void addUser(void* user);
		void removeUser(void* user);
		void addCallback(void* user, event_type type, EventCallback* callback);

		template<class E> void triggerCallbacks(event_type type, E& event)
		{
			for (auto& user : users) {
				if (users.count(type))
					user[type]->call(event);
			}
		}

		std::unordered_map<void*, callback_map> users;
	};

	class EventBus
	{
		friend class Root;
	public:
		EventBus::~EventBus() {}

		template<class T, class E> void addCallback(T* instance, void(T::* method)(E&))
		{
			users.addCallback(instance, E::static_type(), new Callback<T, E>(instance, method));
		}

		template<class E> void post(E& event)
		{
			users.triggerCallbacks(E::static_type(), event);
		}

		void removeUser(void* instance);

	private:
		EventBus::EventBus() {}
		EventBusRegistry users;
	};

}
