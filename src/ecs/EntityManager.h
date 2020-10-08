#pragma once

#include "Entity.h"

namespace Split
{

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		Entity newEntity(void);
		Entity newEntity(const Tag& tag);
		Tag newTag(void);

	private:
		ui64 nextId;
		i64 nextTag;
	};

}
