#include <SDL2/SDL.h>
#include "Engine.hpp"

class Ball
{
	Ball(double radius, double x, double y);
	~Ball();

public:
	double getRadius(){return radius}
	double getX(){return x}
	double getY(){return y}
	SDL_Color getColor(){return color}
	void update(Engine engine);
	void draw();

private:
	double radius();
	double x();
	double y();	
	SDL_Color color();
}