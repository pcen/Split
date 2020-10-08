#include "pch.h"
#include "Entity.h"

namespace Split
{

	i64 constexpr noTag = -1;

	Tag::Tag(i64 tag)
		: tag{ tag }
	{

	}

	Entity::Entity(ui64 id)
		: id{ id },
		tag{ noTag }
	{

	}

	Entity::Entity(ui64 id, i64 tag)
		: id{ id },
		tag{ tag }
	{

	}

}
