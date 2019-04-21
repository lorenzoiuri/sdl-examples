#ifndef _SDL_utils_
#define _SDL_utils_

#include <SDL2/SDL.h>

typedef struct PVector {
	float xPos;
	float yPos;
} PVector;

PVector* PVector_create (float _x, float _y);

void PVector_destroy (PVector* _pv) ;

#endif 