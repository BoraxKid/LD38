#include "EntityFactory.h"

Entity *EntityFactory::createTerrain(uint32_t terrainType, int32_t x)
{
	Entity *entity = nullptr;

	if (terrainType == 0)
	{
		entity = new Entity(x, 0, 8, 2, 7, 8);
		entity->setSprite(SpriteLoader::getInstance().getSprite("terrainBorderLeft"));
	}
	else if (terrainType == 1)
	{
		entity = new Entity(x, 0, 8, 2, 0, 8);
		entity->setSprite(SpriteLoader::getInstance().getSprite("terrainFlat"));
	}
	else if (terrainType == 2)
	{
		entity = new Entity(x, 0, 8, 2, 0, 1);
		entity->setSprite(SpriteLoader::getInstance().getSprite("terrainBorderRight"));
	}
	return (entity);
}
