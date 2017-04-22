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

void Game::handleEvents(const std::queue<sf::Event> &events)
{
}

void Game::update(const sf::Time &elapsedTime)
{
}

void Game::display(sf::RenderWindow &window)
{
	window.draw(this->_terrain);
}
