#include "SDL.h"
#ifdef IS_WINDOWS
#include <windows.h>
#endif
#include "gl/GL.h"
#include <stdio.h>

#undef main

#define println(s) printf(s"\n")

int main()
{
	println("My first workable cmake-cpp app.");
	println("##################################################");
	println();
	println();
	printf("Initializing SDL...");

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		println();
		println("[ERROR]: failed to initialize SDL!\nPress a key to exit...");
		getchar();
		return 1;
	}

	printf("done!");

	SDL_Window *window = SDL_CreateWindow(
		"My first cpp-cmake application",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	bool running = true;


	while (running)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
		}

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}