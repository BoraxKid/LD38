#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_
#pragma once

#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
	AnimatedSprite();
	AnimatedSprite(float frameTime);
	virtual ~AnimatedSprite();

	void addFrame(const sf::Sprite &sprite);
	void update(const sf::Time &elapsedTime);
	void setActive(bool active);

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool _active;
	float _frameTime;
	float _currentFrameTime;
	std::vector<sf::Sprite> _frames;
	std::vector<sf::Sprite>::const_iterator _currentFrame;
};

#endif // ANIMATEDSPRITE_H_
