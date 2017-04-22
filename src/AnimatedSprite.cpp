#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
	: _frameTime(0.0f), _currentFrameTime(0.0f), _active(true)
{
}

AnimatedSprite::AnimatedSprite(float frameTime)
	: _frameTime(frameTime), _currentFrameTime(0.0f), _active(true)
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::addFrame(const sf::Sprite &sprite)
{
	this->_frames.push_back(sprite);
	this->_currentFrame = this->_frames.begin();
	this->_currentFrameTime = 0.0f;
}

void AnimatedSprite::update(const sf::Time &elapsedTime)
{
	if (!this->_active)
		return;
	this->_currentFrameTime += elapsedTime.asSeconds();
	if (this->_currentFrameTime >= this->_frameTime)
	{
		++this->_currentFrame;
		if (this->_currentFrame == this->_frames.end())
			this->_currentFrame = this->_frames.begin();
	}
}

void AnimatedSprite::setActive(bool active)
{
	this->_active = active;
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (!this->_active)
		return;
	states.transform *= this->getTransform();
	target.draw(*this->_currentFrame);
}
