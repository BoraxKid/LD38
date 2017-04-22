#include "Entity.h"

Entity::Entity(int32_t x, int32_t y, uint32_t width, uint32_t height, uint32_t buildableFrom, uint32_t buildableTo)
	: _x(x), _y(y), _width(width), _height(height), _buildableFrom(buildableFrom), _buildableTo(buildableTo)
{
}

Entity::~Entity()
{
}

void Entity::setSprite(const sf::Sprite &sprite)
{
	this->_sprite = sprite;
	this->_sprite.setPosition(static_cast<float>(this->_x), - static_cast<float>(this->_y) - static_cast<float>(this->_height));
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	target.draw(this->_sprite);
}
