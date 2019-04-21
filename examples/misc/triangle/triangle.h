#include <SDL2/SDL.h>

#ifndef _TRIANGLEH_
#define _TRIANGLEH_

// returns the absolute value of src
double my_abs( double src );

double my_max( double n1, double n2, double n3, double n4);
double my_min( double n1, double n2, double n3, double n4);
int my_sign(int n);

/** Renders a non filled isoscel triangle centered at _x, _y
 */ 
void RenderDrawIsoTriangle(SDL_Renderer *Renderer, int _x, int _y, int base, int hei);

/** Renders a filled isoscel triangle centered at _x, _y
 */ 
void RenderFillIsoTriangle(SDL_Renderer *Renderer, int _x, int _y, int base, int hei);

/** Renders an unfilled generic triangle given the edges
 */ 
void RenderDrawTriangle(SDL_Renderer *Renderer, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3);

/** Renders a filled generic triangle given the edges
 */ 
void RenderFillTriangle(SDL_Renderer *Renderer, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3);

#endif

