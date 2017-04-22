#ifndef GAME_H_
#define GAME_H_
#pragma once

#include "SpriteLoader.h"
#include "Terrain.h"

#include <queue>

class Game
{
public:
	Game();
	virtual ~Game();

	void init();
	void handleEvents(const std::queue<sf::Event> &events);
	void update(const sf::Time &elapsedTime);
	void display(sf::RenderWindow &window);

private:
	Terrain _terrain;
};

#endif // GAME_H_
