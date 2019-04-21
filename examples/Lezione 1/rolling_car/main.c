
// Draw a car

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL_utils.h"
#include "shapes.h"
#include "Car.h"

static const int width = 640;
static const int height = 480;
bool running = true;

void processEvents (SDL_Event*);
void quit (SDL_Renderer* renderer, SDL_Window* window, Car* car);

int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Car", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Event event;
    
    SDL_Color bg; bg.r = 70; bg.g = 110; bg.b = 180; bg.a = 255;
    int speed = 2;
    
    Car* car = Car_create( 150, 70, 20 );
    PVector carPos; carPos.xPos = 0; carPos.yPos = height/2;
    Car_setPosition( car, &carPos );
    Car_setColor( car, 255, 255, 0 );
    
    while(running) {
        // Process events
        processEvents(&event);
		  
		  // Compute
		  PVector* currentPosition = Car_getPosition(car);
		  PVector newPosition; 
		  newPosition.xPos = currentPosition->xPos + speed;
		  if (newPosition.xPos > width) {
		  		newPosition.xPos = 0 - car->bodyWid;
		  }
		  newPosition.yPos = currentPosition->yPos;
		  Car_setPosition(car, &newPosition);
		  free(currentPosition);
		  
        // Clear screen with RGB(70,110,180)
        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(renderer);

		  Car_render(renderer, car);

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
	 quit(renderer, window, car);
    return 0;
}

void processEvents (SDL_Event* event) {
	while(SDL_PollEvent(event)) {
		if(event->type == SDL_QUIT) {
			running = false;
		}
   }
}

void quit (SDL_Renderer* renderer, SDL_Window* window, Car* car) {
	 Car_destroy(car);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}