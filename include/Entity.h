#ifndef ENTITY_H_
#define ENTITY_H_
#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	Entity(int32_t x = 0, int32_t y = 0, uint32_t width = 0, uint32_t height = 0, uint32_t buildableFrom = 0, uint32_t buildableTo = 0);
	virtual ~Entity();

	void setSprite(const sf::Sprite &sprite);

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Sprite _sprite;
	int32_t _x;
	int32_t _y;
	uint32_t _width;
	uint32_t _height;
	uint32_t _buildableFrom;
	uint32_t _buildableTo;
};

#endif // ENTITY_H_
