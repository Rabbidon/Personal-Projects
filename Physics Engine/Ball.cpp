#include "Ball.hpp"
#include <cmath>

Ball::Ball(float rad, sf::Vector2f pos, sf::Color col)
{
	speed = 1000;
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

void Ball::update(int width, int height, float dt)
{
	collideWall(width, height);
	position += dt*speed*direction;
	sprite.move(dt*speed*direction);
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
	if (position.x<radius)
	{
		direction.x = -1*direction.x;
		position.x += 2*(radius-position.x);
	}

	if (position.x>width-radius)
	{
		direction.x = -1*direction.x;
		position.x += 2*(width-radius-position.x);
	}
	if (position.y<radius)
	{
		direction.y = -1*direction.y;
		position.y += 2*(radius-position.y);
	}

	if (position.y>height-radius)
	{
		direction.y = -1*direction.y;
		position.y += 2*(height-radius-position.y);
	}
}