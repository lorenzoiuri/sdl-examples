#ifndef _CARH_
#define _CARH_

#include "SDL_utils.h" 
#include "circle.h"

typedef struct Car {
	PVector pos;
	int bodyWid;
	int bodyHei;
	int wheelRadius;
	SDL_Color color;
} Car;

/** Creates a car and setup its data structures
 *  default color is black
 *  default position is (0,0)
 *  returns a pointer to the car, must be destroyed after use
 */
Car* Car_create (int _bodyWid, int _bodyHei, int _wheelRadius);

/** Modify the color of the car
 */
void Car_setColor (Car* car, int _r, int _g, int _b);

/** Renders the car using the specified renderer
 *  does not modify car
 */
void Car_render (SDL_Renderer* renderer, const Car* car);

/** Returns a pointer to a new PVector that contains the position of car
 *  does not modify car
 */
PVector* Car_getPosition (const Car* car);

/** Set a new position for car using data in _pos
 *  does not modify _pos
 */
void Car_setPosition (Car* car, const PVector* _pos);

/** Frees the resources allocated to car
 *  modifies car
 */
void Car_destroy (Car* car);
#endif
