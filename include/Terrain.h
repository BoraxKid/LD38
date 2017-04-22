#ifndef TERRAIN_H_
#define TERRAIN_H_
#pragma once

#include "Entity.h"
#include "EntityFactory.h"

#include <cstdlib>

class Terrain : public sf::Drawable, public sf::Transformable
{
public:
	Terrain();
	virtual ~Terrain();

	void generate();

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	std::vector<Entity *> _terrainEntities;
};

#endif // TERRAIN_H_
