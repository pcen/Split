#pragma once

#include "event_callback.h"

namespace Split
{

	class EventBusClientMap
	{
	public:
		typedef std::vector<AEventCallback*> callback_list;
		typedef std::unordered_map<event_type, callback_list> user_callbacks;
		typedef std::unordered_map<void*, user_callbacks> user_map;

		EventBusClientMap() {}
		~EventBusClientMap()
		{
			for (auto& bus_user : bus_users) {
				for (auto& user_callbacks : bus_user.second) {
					for (auto& callback : user_callbacks.second)
						delete callback;
				}
			}
		}

		bool has_user(void* user);
		void add_user(void* user);
		void remove_user(void* user);
		void add_callback(void* user, event_type type, AEventCallback* callback);

		template<class E> void trigger_callbacks(event_type type, E& event)
		{
			for (auto& user : bus_users) {
				call_generic_callbacks(user.second, event);
				call_specialized_callbacks(user.second, type, event);
			}
		}

		template<class E> void call_generic_callbacks(user_callbacks& user, E& event)
		{
			if (!user.count(event_type::GENERIC))
				return;

			for (auto& callback : user[event_type::GENERIC])
				callback->call(event);
		}

		template<class E> void call_specialized_callbacks(user_callbacks& user, event_type type, E& event)
		{
			if (!user.count(type))
				return;

			for (auto& callback : user[type])
				callback->call(event);
		}

		user_map bus_users;
	};

	class EventBus
	{
		friend class Root;
	public:
		EventBus::~EventBus() {}

		template<class T, class E> void add_callback(T* instance, void(T::* method)(E&))
		{
			if (!users.has_user(instance))
				users.add_user(instance);

			users.add_callback(instance, E::static_type(), new EventCallback<T, E>(instance, method));
		}

		template<class T> void remove_user(T* instance)
		{
			users.remove_user(instance);
		}

		template<class E> void post(E& event)
		{
			users.trigger_callbacks(E::static_type(), event);
		}

	private:
		EventBus::EventBus() {}
		EventBusClientMap users;
	};

}
