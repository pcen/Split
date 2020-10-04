#pragma once

#include "pch.h"

#define NAME_EVENT(eventName) std::string name(void) const override { return (eventName); }

namespace Split
{

	class Event
	{
	public:
		virtual ~Event() {}
		virtual std::string getName(void) { return name(); }

	protected:
		virtual std::string name(void) const = 0;
	};

}
