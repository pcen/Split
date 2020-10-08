#include "pch.h"
#include "EntityManager.h"

namespace Split
{

    EntityManager::EntityManager()
        : nextId{ 0 },
        nextTag{ 0 }
    {

    }

    EntityManager::~EntityManager()
    {

    }

    Entity EntityManager::newEntity(void)
    {
        return Entity(nextId++);
    }

    Entity EntityManager::newEntity(const Tag& tag)
    {
        return Entity(nextId++, tag.tag);
    }

    Tag EntityManager::newTag(void)
    {
        return Tag(nextTag++);
    }

}
