#include "PhysicsContext.hpp"

Context *context = nullptr;
int main()
{
	context = new Context();

	context->init("TestEngine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);

	while(context->running())
	{
		context->handleEvents();
		context->update();
		context->render();
	}

	context->clean();

	return 0;
}
