#include "Terrain.h"

Terrain::Terrain()
{
}

Terrain::~Terrain()
{
}

void Terrain::generate()
{
	uint32_t length = std::rand() % 5 + 1;
	uint32_t i = 0;
	int32_t x = 8;

	this->_terrainEntities.push_back(EntityFactory::createTerrain(0, x - 8));
	while (i < length)
	{
		this->_terrainEntities.push_back(EntityFactory::createTerrain(1, x));
		x += 8;
		++i;
	}
	this->_terrainEntities.push_back(EntityFactory::createTerrain(2, x));
}

void Terrain::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	for (const auto &entity : this->_terrainEntities)
		target.draw(*entity);
}
