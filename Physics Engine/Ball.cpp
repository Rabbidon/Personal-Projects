#include "Ball.hpp"

Ball::Ball(float rad, sf::Vector2f pos, sf::Color col)
{
	radius = rad;
	position = pos;
	color = col;
	sf::CircleShape s(radius);
	sprite = s;
	sprite.setFillColor(sf::Color(100, 250, 50));
	sprite.setPosition(position);
}

Ball::~Ball()
{

}

void Ball::update()
{
	std::cout << position.x << std::endl;
	std::cout << position.y << std::endl;
	position = sf::Vector2f(0.f,0.f);
	std::cout << position.x << std::endl;
	std::cout << position.y << std::endl;
}

void Ball::draw(sf::RenderWindow *window)
{
	window->draw(sprite);
	sprite.setFillColor(sf::Color(100, 250, 50));
	sprite.setPosition(position + sf::Vector2f(-50.f,-50.f));
}