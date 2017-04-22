#include "Application.h"

Application::Application(const std::string &windowTitle)
	: _window(sf::VideoMode(1280, 720), windowTitle)
{
}

Application::~Application()
{
}

void Application::init()
{
	srand(time(0));
	this->_gameUpdateClock.restart();
	this->_game.init();
	this->_view = this->_window.getDefaultView();
	this->_view.setSize(sf::Vector2f(1280.0f / 8.0f, 720.0f / 8.0f));
	this->_view.setCenter(sf::Vector2f(0.0f, -(this->_view.getSize().y / 2.0f) + 14.0f));
	this->_window.setView(this->_view);
}

int Application::run()
{
	while (this->_window.isOpen())
	{
		this->handleEvents();
		this->update();
		this->display();
	}
	return (0);
}

void Application::handleEvents()
{
	std::queue<sf::Event> queuedEvents;
	sf::Event event;

	while (this->_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->_window.close();
		else if (event.type == sf::Event::Resized)
			; // TODO: Properly handle window's resize
		else
			queuedEvents.push(event);
	}
	if (this->_window.isOpen())
		this->_game.handleEvents(queuedEvents);
}

void Application::update()
{
	this->_game.update(this->_gameUpdateClock.restart());
}

void Application::display()
{
	this->_window.clear(sf::Color(83, 167, 230));
	this->_game.display(this->_window);
	this->_window.display();
}
