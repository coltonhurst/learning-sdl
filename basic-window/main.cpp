#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_HEIGHT = 640;
const int WINDOW_WIDTH = 480;

// Starting point.
int main(int argc, const char * argv[])
{
    // Create the window & screen surface.
    // We render to the window & the surface is "contained" by the window.
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;
    
    // Initiate SDL. If an error occurs, stop & print the error.
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized. SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        // Create the window.
        window = SDL_CreateWindow("Window Title",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  WINDOW_HEIGHT,
                                  WINDOW_WIDTH,
                                  SDL_WINDOW_OPENGL);
        
        // If the window can't be created, print the error.
        if (window == nullptr)
        {
            std::cout << "The window couldn't be created. SDL_Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            // Get the window's surface.
            screenSurface = SDL_GetWindowSurface(window);
            
            // Make the screen surface white.
            SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            
            // Update the surface.
            SDL_UpdateWindowSurface(window);
            
            SDL_Event event;
            bool quit = false;
            
            // Event loop.
            while (!quit) {
                while (SDL_PollEvent(&event) != 0) {
                    if (event.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
            }
        }
    }
    
    // Destroy the window.
    SDL_DestroyWindow( window );

    // Quit SDL.
    SDL_Quit();
    
    return 0;
}

