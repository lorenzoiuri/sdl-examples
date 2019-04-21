
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "triangle.h"

static const int width = 640;
static const int height = 480;
bool running = true;

void processEvents (SDL_Event*);
void quit (SDL_Renderer* renderer, SDL_Window* window);

int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Event event;
    
    //SDL_Color bg; bg.r = 70; bg.g = 110; bg.b = 180; bg.a = 255;
    SDL_Color bg; bg.r = 255; bg.g = 255; bg.b = 255; bg.a = 255;
    
    while(running) {
        // Process events
        processEvents(&event);
		  
		  // Compute
		 
		  
        // Clear screen with RGB(70,110,180)
        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(renderer);

		  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		  //RenderFillIsoTriangle(renderer, width/2, height/2, 150, 150);
		  RenderFillTriangle(renderer, 250*1.2, 300*1.2, 300*1.2, 350*1.2, 330*1.2, 260*1.2);

        // Show what was drawn
        SDL_RenderPresent(renderer);
        //running = false;
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