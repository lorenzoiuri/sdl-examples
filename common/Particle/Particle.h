/**
 *  ADT for a particle
 */

#ifndef _PARTICLEH_
#define _PARTICLEH_
 
#include "SDL_utils.h"

typedef struct Particle {
	int radius;
	PVector pos;
	PVector vel;
	PVector acc;
	SDL_Color color;	
} Particle;

/** Creates a particle and setup its data structures
 *  default color is black
 *  default position is (0,0)
 *  returns a pointer to the particle, must be destroyed after use
 */
Particle* Particle_create (int _radius);

/** Modify the color of the particle
 */
void Particle_setColor (Particle* particle, int _r, int _g, int _b, int _a);

/** Renders the particle using the specified renderer
 *  does not modify particle
 */
void Particle_render (SDL_Renderer* renderer, const Particle* particle);

/** Returns a pointer to a new PVector that contains the position of particle
 *  does not modify particle
 */
PVector* Particle_getPosition (const Particle* particle);

/** Set a new position for particle using data in _pos
 *  does not modify _pos
 */
void Particle_setPosition (Particle* particle, const PVector* _pos);

/** Returns a pointer to a new PVector that contains the speed of particle
 *  does not modify particle
 */
PVector* Particle_getSped (const Particle* particle);

/** Set a new speed for particle using data in _vel
 *  does not modify _vel
 */
void Particle_setSpeed (Particle* particle, const PVector* _vel);

/** Returns a pointer to a new PVector that contains the acceleration of particle
 *  does not modify particle
 */
PVector* Particle_getAcceleration (const Particle* particle);

/** Set a new acceleration for particle using data in _acc
 *  does not modify _acc
 */
void Particle_setAcceleration (Particle* particle, const PVector* _acc);

/** Frees the resources allocated to particle
 *  modifies particle
 */
void Particle_destroy (Particle* particle);

void Particle_updatePosition (Particle* particle, const PVector* windowData);

void checkBorders (Particle* particle, const PVector* windowData);

#endif