
// Draw a car

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL_utils/Circle/Circle.h"

static const int width = 640;
static const int height = 480;
bool running = true;

void processEvents (SDL_Event*);
void quit (SDL_Renderer* renderer, SDL_Window* window);

int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Car", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Event event;
    
    
    while(running) {
        // Process events
        processEvents(&event);
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        RenderFillCircle(renderer, 100, 100, 25);
        
        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
	 quit(renderer, window);
    return 0;
}

void processEvents (SDL_Event* event) {
	while(SDL_PollEvent(event)) {
		if(event->type == SDL_QUIT) {
			running = false;
		}
   }
}

void quit (SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
