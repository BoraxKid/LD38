#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	SpriteLoader::getInstance().load();
	this->_terrain.generate();
}

void Game::handleEvents(std::queue<sf::Event> &events)
{
	sf::Event event;

	while (!events.empty())
	{
		event = events.front();
		events.pop();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::A)
				;
		}
	}
}

void Game::update(const sf::Time &elapsedTime)
{
}

void Game::display(sf::RenderWindow &window)
{
	window.draw(this->_terrain);
}
