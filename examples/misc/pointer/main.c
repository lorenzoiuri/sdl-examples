
// Draw the mouse movement

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

static const int width = 800;
static const int height = 600;
bool running = true;

void processEvents (SDL_Event*);
void quit (SDL_Renderer* renderer, SDL_Window* window);

int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Mouse draw", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    srand(time(NULL));
    
    // data structure that contains the background color
    SDL_Color bg; bg.r = 0; bg.g = 0; bg.b = 0; bg.a = 255;
    
    int mouseX, mouseY;
    int fatness = 30;
    
    while(running) {
        // Process events
        processEvents(&event);
		  
		  // Get the new positions
		  SDL_GetMouseState(&mouseX, &mouseY);
		  
        // Clear screen backgroundcolor
        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(renderer);
	
		  // Render the point
		  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
   	  SDL_Rect m = {mouseX - fatness/2, mouseY - fatness/2, fatness, fatness};
        SDL_RenderFillRect(renderer, &m);
		
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