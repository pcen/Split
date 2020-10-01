#include "pch.h"
#include "event_bus.h"

namespace Split
{

	bool EventBusClientMap::has_user(void* user)
	{
		return bus_users.count(user) != 0;
	}

	void EventBusClientMap::add_user(void* user)
	{
		if (!has_user(user))
			bus_users[user] = user_callbacks();
	}

	void EventBusClientMap::remove_user(void* user)
	{
		if (!has_user(user))
			return;
		for (auto& callback_list : bus_users[user]) {
			for (auto& callback : callback_list.second)
				delete callback;
		}
		bus_users.erase(user);
	}

	void EventBusClientMap::add_callback(void* user, event_type type, AEventCallback* callback)
	{
		if (!has_user(user))
			return;

		if (!bus_users[user].count(type))
			(bus_users[user])[type] = callback_list();

		(bus_users[user])[type].push_back(callback);
	}

}