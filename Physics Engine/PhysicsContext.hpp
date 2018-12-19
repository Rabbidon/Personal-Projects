#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>

//Header file for the Physics Context class.
class Context{
	public:

		Context();
		~Context();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

		void handleEvents();
		void update();
		void render();
		void clean();

		bool running(){return isRunning;}

	private:
		bool isRunning;
		SDL_Window *window;
		SDL_Renderer *renderer;
};