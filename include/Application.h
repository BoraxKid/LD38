#ifndef APPLICATION_H_
#define APPLICATION_H_
#pragma once

#include "Game.h"

#include <queue>
#include <SFML/Graphics.hpp>

class Application
{
public:
	Application(const std::string &windowTitle);
	virtual ~Application();

	void init();
	int run();

private:
	void handleEvents();
	void update();
	void display();

	sf::RenderWindow _window;
	sf::View _view;
	Game _game;
	sf::Clock _gameUpdateClock;
};

#endif // APPLICATION_H_
