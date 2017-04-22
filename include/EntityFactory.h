#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_
#pragma once

#include "Entity.h"
#include "SpriteLoader.h"

class EntityFactory
{
public:
	static Entity *createTerrain(uint32_t terrainType, int32_t x);
};

#endif // ENTITYFACTORY_H_
