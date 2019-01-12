#include <SFML/Graphics.hpp>
#include <iostream>

class Ball
{

public:

	Ball(float radius, sf::Vector2f position, sf::Color color);

	~Ball();

	sf::Color getColor(){return color;}
	sf::Vector2f getPosition(){return position;}
	void update(int width, int height, float dt);
	void draw(sf::RenderWindow *window);
	void collideBall(Ball);
	void collideWall(int width, int height);

private:
    float radius;
    float speed;
    float angle;
    sf::CircleShape sprite;
    sf::Color color;
    sf::Vector2f position;
    sf::Vector2f direction;
};