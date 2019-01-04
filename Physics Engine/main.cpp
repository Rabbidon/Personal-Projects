#include "PhysicsContext.hpp"

Context *context = nullptr;
int main()
{
	srand(time(NULL));

	context = new Context(0.1);

	context->run("TestEngine",sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height,true);

	return 0;
}
