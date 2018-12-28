#include <SFML/Graphics.hpp>
#include <stdio.h>

//Header file for the Physics Context class.
class Context{
	public:

		Context();
		~Context();

		void run(const char* title, int width, int height, bool fullscreen);

		void handleEvents();
		void update();
		void render();

	private:
		sf::RenderWindow *window;
};