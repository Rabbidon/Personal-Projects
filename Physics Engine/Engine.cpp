#include "Engine.hpp"
#include <iostream>

Engine::Engine(float cool)
	{
		cooldown = cool;
		time = clock();
		width = sf::VideoMode::getDesktopMode().width;
		height = sf::VideoMode::getDesktopMode().height;
	}

Engine::~Engine()
{

}

void Engine::update()
{
	for (Ball& ball : balls)
	{
		ball.update(width,height);
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::X)) & (cooldown<((float)(clock()-time))/CLOCKS_PER_SEC))
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