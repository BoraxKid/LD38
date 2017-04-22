#ifndef SPRITELOADER_H_
#define SPRITELOADER_H_
#pragma once

#include "AnimatedSprite.h"

class SpriteLoader
{
public:
	SpriteLoader(SpriteLoader const &) = delete;
	void operator=(SpriteLoader const &) = delete;

	void load();
	const sf::Sprite &getSprite(const std::string &key) const;
	const AnimatedSprite &getAnimatedSprite(const std::string &key) const;

	static SpriteLoader &getInstance()
	{
		static SpriteLoader instance;
		return (instance);
	}

private:
	SpriteLoader() {}

	void loadTextures();
	void loadSprites();

	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Sprite> _sprites;
	std::map<std::string, AnimatedSprite> _animatedSprites;
};

#endif // SPRITELOADER_H_
