#include <SDL2/SLD.h>

class Ball
{
public:
	double getRadius();
	double getX();
	double getY();
	SDL_Color getColor();
	void update();
	void draw();

private:
	double radius();
	double x();
	double y();	
}