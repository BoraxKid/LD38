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
	this->_toolBar.init();
	this->_toolBar.addAvailableEntity(SpriteLoader::getInstance().getSprite("woodenHouse4"));
}

void Game::handleEvents(std::queue<sf::Event> &events)
{
	sf::Event event;

	while (!events.empty())
	{
		event = events.front();
		events.pop();
	}
}

void Game::update(const sf::Time &elapsedTime)
{
}

void Game::display(sf::RenderWindow &window)
{
	window.draw(this->_terrain);
	window.draw(this->_toolBar);
}
