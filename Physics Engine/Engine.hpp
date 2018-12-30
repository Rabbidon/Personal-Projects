#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Engine
{

public:

	Engine(float cool);
	~Engine();

	void update();
	void drawAll(sf::RenderWindow *window);
	void spawn(Ball);

	float cooldown;

private:

	std::vector<Ball> balls;
	time_t time;
};