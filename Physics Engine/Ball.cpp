#include "Ball.hpp"

Ball::Ball(float rad, sf::Vector2f pos, sf::Color col)
{
	radius = rad;
	position = pos;
	color = col;
	sf::CircleShape s(radius);
	sprite = s;
	sprite.setFillColor(sf::Color(100, 250, 50));
	sprite.setPosition(position + sf::Vector2f(-1*radius,-1*radius));
}

Ball::~Ball()
{

}

void Ball::update()
{
	position += sf::Vector2f(1.f,1.f);
	sprite.setFillColor(sf::Color(100, 250, 50));
	sprite.setPosition(position + sf::Vector2f(-1*radius,-1*radius));
}

void Ball::draw(sf::RenderWindow *window)
{
	window->draw(sprite);
}