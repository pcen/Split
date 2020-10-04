#include "pch.h"
#include "EventBus.h"

namespace Split
{
	// EventBusRegistry Implementation

	EventBusRegistry::EventBusRegistry() {}

	EventBusRegistry::~EventBusRegistry()
	{
		for (auto& user : users) {
			for (auto& c : user.second) {
				delete c.second;
			}
		}
	}

	bool EventBusRegistry::hasUser(void* user)
	{
		return users.count(user) != 0;
	}

	void EventBusRegistry::addUser(void* user)
	{
		if (!hasUser(user))
			users[user] = callback_map();
	}

	void EventBusRegistry::removeUser(void* user)
	{
		if (!hasUser(user))
			return;
		for (auto& callback : users[user]) {
			delete callback.second;
		}
		users.erase(user);
	}

	void EventBusRegistry::addCallback(void* user, const std::type_info& type, EventCallback* callback)
	{
		if (!hasUser(user))
			addUser(user);

		if (!users[user].count(type))
			(users[user])[type] = callback;
	}

	// EventBus Implementation

	void EventBus::removeUser(void* instance)
	{
		users.removeUser(instance);
	}

}
