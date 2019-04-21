#ifndef _CIRCLEH_
#define _CIRCLEH_

#include "SDL_utils.h"

/** Renders a circle centered at _x, _y
 */ 
void RenderDrawCircle(SDL_Renderer *Renderer, int _x, int _y, int radius);

/** Renders a circle centered at _x, _y
 */ 
void RenderFillCircle(SDL_Renderer *Renderer, int _x, int _y, int radius);

#endif

