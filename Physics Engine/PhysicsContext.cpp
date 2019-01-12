#include "PhysicsContext.hpp"
#include <iostream>

Context::Context()
{

}
Context::~Context()
{

}

void Context::run(const char* title, int width, int height, bool fullscreen)
{
	int style = sf::Style::Default;
	if(fullscreen)
	{
		style = sf::Style::Fullscreen;
	}

	sf::RenderWindow app(sf::VideoMode(width, height), "Test Window", style);
	window = &app;
	Engine eng = Engine();
	engine = &eng;

	while (window->isOpen())
    {
        handleEvents();
        update();
        render();
    }

}

void Context::handleEvents()
{
	sf::Event event;
	while(window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					mousePressed = true;
				}
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					window->close();
					break;
				}
			default:
				break;
		}
	}
}

void Context::update()
{
	float dt = clock.getElapsedTime().asSeconds();
	clock.restart();
	engine->update(mousePressed,dt);
	mousePressed = false;
}

void Context::render()
{
	window->clear(sf::Color::Black);
	engine->drawAll(window);
	window->display();
}


