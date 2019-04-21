
#include <stdio.h>
#include <stdbool.h>
#include "SDL_utils.h"
#include "utils.h"
#include "Particle.h"

static const int width = 640;
static const int height = 480;
bool running = true;

void processEvents (SDL_Event*);
void quit (SDL_Renderer* renderer, SDL_Window* window);

int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Particle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    
    initRand();
    SDL_Color bg; bg.r = 70; bg.g = 110; bg.b = 180; bg.a = 255;
    
    PVector windowData; windowData.x = width; windowData.y = height;
    
    Particle* part = Particle_create(30);
    PVector pos; pos.x = width/2; pos.y = height/4;
    Particle_setPosition(part, &pos);
    PVector vel; vel.x = 0; vel.y = 0;
    Particle_setSpeed(part, &vel);
    PVector acc; acc.x = 0; acc.y = randf(0,0.5);
    Particle_setAcceleration(part, &acc);
    Particle_setColor(part, 255, 180, 0, 0);
    
    while(running) {
        // Process events
        processEvents(&event);
		  
		  // Compute
		  Particle_updatePosition(part, &windowData);
		  
        // Clear screen with RGB(70,110,180)
        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(renderer);
        
        Particle_render(renderer, part);

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
	 quit(renderer, window);
	 Particle_destroy(part);
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