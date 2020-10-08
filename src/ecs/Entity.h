#pragma once

namespace Split
{

	class Tag
	{
		friend class EntityManager;
		Tag(i64 tag);
		i64 tag;
	};

	class Entity
	{
		friend class EntityManager;
		Entity(ui64 id);
		Entity(ui64 id, i64 tag);
		ui64 id;
		i64 tag;
	};

}
