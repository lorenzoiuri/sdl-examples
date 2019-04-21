
// Draw some cars

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL_utils.h"
#include "car.h"

static const int width = 1280;
static const int height = 720;
bool running = true;

void processEvents (SDL_Event*);
void quit (SDL_Renderer* renderer, SDL_Window* window, Car** cars, PVector** positions, int ncars);

int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Car", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    srand(time(NULL));
    
    // data structure that contains the background color
    SDL_Color bg; bg.r = 0; bg.g = 0; bg.b = 0; bg.a = 255;
    
    // number of cars to draw
    int ncars = 40;
    
    // initializing the cars
    Car* cars[ncars];
    for (int i=0; i<ncars; i++) {
    	cars[i] = Car_create(30*3, 14*3, 4*3);
    }
    
    // initializing the PVectors, each contains the position of a car
    PVector* positions[ncars];
    for (int i=0; i<ncars; i++) {
    	PVector* v = PVector_create(0,0);
    	v->xPos = rand() % width;
    	v->yPos = rand() % height;
    	positions[i] = v;
    }
    
    // array containing the speed of each car
    int speeds[ncars];
    for (int i=0; i<ncars; i++) {
    	speeds[i] = (rand() % 5)+1;
    }
    
    // setting the position to the car and the color
	 for (int i=0; i<ncars; i++) {
    	Car_setPosition( cars[i], positions[i] );
    	Car_setColor( cars[i], rand() % 256, rand() % 256, rand() % 256 );
    }
    
    while(running) {
        // Process events
        processEvents(&event);
		  
		  // Compute the new positions
		  for (int i=0; i<ncars; i++) {
		  		PVector* currentPosition = Car_getPosition(cars[i]);
		  		PVector newPosition; 
		  		newPosition.xPos = currentPosition->xPos + speeds[i];
		  		if (newPosition.xPos > width) {
		  				newPosition.xPos = 0 - cars[i]->bodyWid;
		  		}
		  		newPosition.yPos = currentPosition->yPos;
		  		Car_setPosition(cars[i], &newPosition);
		  		free(currentPosition);
		  }
		  
        // Clear screen backgroundcolor
        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(renderer);
	
		  // Render the cars
		  for (int i=0; i<ncars; i++) {		  
		  		Car_render(renderer, cars[i]);
		  }

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
	 quit(renderer, window, cars, positions, ncars);
    return 0;
}

void processEvents (SDL_Event* event) {
	while(SDL_PollEvent(event)) {
		if(event->type == SDL_QUIT) {
			running = false;
		}
   }
}

void quit (SDL_Renderer* renderer, SDL_Window* window, Car** cars, PVector** positions, int ncars) {
	 for (int i=0; i<ncars; i++) {
	 	Car_destroy( cars[i] );
	 	PVector_destroy( positions[i] );
	 }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
