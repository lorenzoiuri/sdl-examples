%  ADT for a shooting character

#ifndef _SHOOTERH_
#define _SHOOTERH_

#include "SDL_utils"
#include "Vector"
#include <stdlib.h>

#define COLOR_COMPONENTS 3

typedef struct Shooter {
    PVector* pos; // x,y coordinates
    int* color;   // the color of the character
    char facing;  // if the character is facing left (l) or right (r)
} Shooter;

/** Allocates the resources for a character shooter
 *  _x, _y are the initial positions of the character
 * returns the pointer to the character created
 */
Shooter* Shooter_createShooter(int _x, int _y);


void Shooter_renderShooter(SDL_Renderer renderer, Shooter* sh);

/** Sets the color of the character
 *  returns 1 if all ok
 */
int Shooter_setColor(Shooter* sh, int _r, int _g, int _b, int _a);

/** Obtains the current position of the character
 *  and puts the values into tha argument variables
 *  returns 1 if all ok
 */
int Shooter_getPosition(Shooter* sh, int& _x, int& _y);

/**
 * Replaces the current position of the character
 * return 1 if all ok
 */
int Shooter_setPosition(Shooter* sh, int _x, int _y);


/** Deallocates the resources of the character
 *  returns 1 if all ok
 */
int Shooter_destroyShooter(Shooter* sh);

int Shooter_shoot(Shooter* sh);

