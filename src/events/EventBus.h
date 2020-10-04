#pragma once

#include "EventCallback.h"

namespace Split
{

	class EventBusRegistry
	{
	public:
		typedef std::unordered_map<std::type_index, EventCallback*> callback_map;

		EventBusRegistry();
		~EventBusRegistry();

		bool hasUser(void* user);
		void addUser(void* user);
		void removeUser(void* user);
		void addCallback(void* user, const std::type_info& type, EventCallback* callback);

		template<class E> void triggerCallbacks(const std::type_info type, E& event)
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
			users.addCallback(instance, typeid(E), new Callback<T, E>(instance, method));
		}

		template<class E> void post(E& event)
		{
			users.triggerCallbacks(typeid(E), event);
		}

		void removeUser(void* instance);

	private:
		EventBus::EventBus() {}
		EventBusRegistry users;
	};

}
