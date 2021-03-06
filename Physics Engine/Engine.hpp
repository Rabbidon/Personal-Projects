#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Engine
{

public:

	Engine();
	~Engine();

	void update(bool mousePressed, float dt);
	void drawAll(sf::RenderWindow *window);
	void spawn(Ball);

private:

	std::vector<Ball> balls;
	time_t time;
	int width;
	int height;
};