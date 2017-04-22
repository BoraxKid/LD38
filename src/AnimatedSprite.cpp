#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
	: _frameTime(0.0f), _currentFrameTime(0.0f)
{
}

AnimatedSprite::AnimatedSprite(float frameTime)
	: _frameTime(frameTime), _currentFrameTime(0.0f)
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
	this->_currentFrameTime += elapsedTime.asSeconds();
	if (this->_currentFrameTime >= this->_frameTime)
	{
		++this->_currentFrame;
		if (this->_currentFrame == this->_frames.end())
			this->_currentFrame = this->_frames.begin();
	}
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	target.draw(*this->_currentFrame);
}
