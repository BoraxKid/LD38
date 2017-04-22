#include "Entity.h"

Entity::Entity(int32_t x, int32_t y, uint32_t width, uint32_t height, bool buildable)
	: _x(x), _y(y), _width(width), _height(height), _buildable(buildable)
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

bool Entity::isBuildable() const
{
	return (this->_buildable);
}

void Entity::setBuildable(bool buildable)
{
	this->_buildable = buildable;
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	target.draw(this->_sprite);
}
