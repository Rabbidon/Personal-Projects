#include "Engine.hpp"
#include <iostream>

Engine::Engine()
	{

		time = clock();
		width = sf::VideoMode::getDesktopMode().width;
		height = sf::VideoMode::getDesktopMode().height;
	}

Engine::~Engine()
{

}

void Engine::update(bool mousePressed, float dt)
{
	for (Ball& ball : balls)
	{
		ball.update(width,height,dt);
	}
	if(mousePressed)
	{
		time = clock();
		Ball newBall = Ball(50.f,static_cast<sf::Vector2f>(sf::Mouse::getPosition()),sf::Color(100, 250, 50));
		spawn(newBall);
	}

}

void Engine::spawn(Ball newBall)
{
	balls.push_back(newBall);
}

void Engine::drawAll(sf::RenderWindow *window)
{
	for (Ball ball : balls)
	{
		ball.draw(window);
	}
}