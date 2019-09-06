#include "SDL.h"
#ifdef IS_WINDOWS
  #include <windows.h>
#endif
#include "GL/gl.h"
#include <stdio.h>
#include <vector>

#undef main

 // https://www.40tude.fr/blog/compile-cpp-code-with-vscode-cmake-nmake/

int main() 
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
      "My first cpp-cmake application",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      640,
      480,
      SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    std::vector<int> vec;
    vec.push_back(1);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GLContext context = SDL_GL_CreateContext(window);

    bool running = true;

    printf("CULO");

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