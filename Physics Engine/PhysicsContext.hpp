#include "Engine.hpp"
#include <SFML/Graphics.hpp>

//Header file for the Physics Context class.
class Context
{
	public:

		Context(float cool);
		~Context();

		void run(const char* title, int width, int height, bool fullscreen);

		void handleEvents();
		void update();
		void render();

	private:
		sf::RenderWindow *window;
		Engine *engine;
		float cooldown;
};