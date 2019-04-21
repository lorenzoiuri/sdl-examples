// Lesson 1


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shapes.h"

//#include <SDL2/SDL.h> 

static const int width = 600;
static const int height = 480;
bool running = true;

void processEvents (SDL_Event*);
void quit (SDL_Renderer* renderer, SDL_Window* window);
void changeXPos(int* xpos, int* movingDirection, int screenWidth, int rectWidth, int speed);

int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Event event;
    
    int xpos = 0;
    int movingDirection = 1;
    int rectWidth = 25;
    int speed = 5;
    
    while(running) {
        // Process events
        processEvents(&event);
		  
		  // Compute
		  changeXPos(&xpos, &movingDirection, width, rectWidth, speed );
		  
        // Clear screen with RGB(70,110,180)
        SDL_SetRenderDrawColor(renderer, 70, 110, 180, 255);
        SDL_RenderClear(renderer);

        // Draw a rectangle with RGB yellow
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_Rect rect = {xpos, 0, rectWidth, 100};
        
        SDL_RenderFillRect(renderer, &rect);
        //RenderCircle(renderer, 100, 100, 100);

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

void changeXPos(int* xpos, int* movingDirection, int screenWidth, int rectWidth, int speed) {
	if (*movingDirection == 1) { //moving left to right
		*xpos+=speed;
		if (*xpos > screenWidth - rectWidth) {
			*xpos = screenWidth - rectWidth;
			*movingDirection = 0;
		} 
	} else { // moving right to left
		*xpos-=speed;
		if (*xpos < 0) {
			*xpos = 0 ;
			*movingDirection = 1;
		} 
	}
}