#include <SDL2/SDL.h>
#include <iostream>

int main(int argv, char** args)  {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Surface *screen = SDL_GetWindowSurface(window);
    Uint32 white = SDL_MapRGB(screen->format, 10, 200, 10);
    SDL_FillRect(screen, NULL, white);
    SDL_UpdateWindowSurface(window);
    // Give some time for the window to be visible
    SDL_Delay(2000);

    // Destroy the window and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
