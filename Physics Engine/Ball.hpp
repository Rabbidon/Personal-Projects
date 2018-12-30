#include <SFML/Graphics.hpp>
#include <iostream>

class Ball
{

public:

	Ball(float radius, sf::Vector2f position, sf::Color color);

	~Ball();

	sf::Color getColor(){return color;}
	sf::Vector2f getPosition(){return position;}
	void update();
	void draw(sf::RenderWindow *window);

private:
    float radius;
    sf::CircleShape sprite;
    sf::Color color;
    sf::Vector2f position;
};