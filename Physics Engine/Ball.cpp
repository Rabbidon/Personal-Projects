#include "Ball.hpp"
#include <cmath>

Ball::Ball(float rad, sf::Vector2f pos, sf::Color col)
{
	speed = 5;
	angle = (rand() % 1000000)*(2*M_PI)/1000000;
	direction = sf::Vector2f(sin(angle),cos(angle));
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

void Ball::update(int width, int height)
{
	collideWall(width, height);
	position += speed*direction;
	sprite.move(speed*direction);
	sprite.setFillColor(sf::Color(100, 250, 50));
}

void Ball::draw(sf::RenderWindow *window)
{
	window->draw(sprite);
}

void Ball::collideBall(Ball other)
{

}

void Ball::collideWall(int width, int height)
{
	if ((position.x<radius) or (position.x>width-radius))
	{
		direction.x = -1*direction.x;
	}
	if ((position.y<radius) or (position.y>height-radius))
	{
		direction.y = -1*direction.y;
	}
}