	
#include "Particle.h"

Particle* Particle_create (int _radius) {
	if (_radius < 0) {
		return NULL;
	}
	Particle* p = (Particle*) malloc( sizeof(Particle) );
	p->radius = _radius;
	p->pos.x = 0;
	p->pos.y = 0;
	p->vel.x = 0;
	p->vel.y = 0;
	p->acc.x = 0;
	p->acc.y = 0;
	p->color.r = 0;
	p->color.g = 0;
	p->color.b = 0;
	p->color.a = 255;
	return p;
}

void Particle_setColor (Particle* p, int _r, int _g, int _b, int _a) {
	if (p == NULL) return;
	if (_r < 0 || _r > 255) return;
	if (_g < 0 || _g > 255) return;
	if (_b < 0 || _b > 255) return;
	if (_a < 0 || _a > 255) return;
	
	p->color.r = _r;
	p->color.g = _g;
	p->color.b = _b;
	p->color.a = _a;
}


void Particle_render (SDL_Renderer* renderer, const Particle* p) {
	if (p == NULL) return;
	SDL_SetRenderDrawColor(renderer, p->color.r, p->color.g, p->color.b, p->color.a);
	RenderFillCircle(renderer, p->pos.x, p->pos.y, p->radius);
}

PVector* Particle_getPosition (const Particle* particle) {
	if (particle == NULL) return NULL;
	PVector* pv = (PVector*) malloc( sizeof(Particle) );
	pv->x = particle->pos.x;
	pv->y = particle->pos.y;
	return pv;
}

void Particle_setPosition (Particle* particle, const PVector* _pos) {
	if (particle == NULL) return;
	if (_pos == NULL) return;
	particle->pos.x = _pos->x;
	particle->pos.y = _pos->y;	
}

void Particle_setSpeed (Particle* particle, const PVector* _vel)  {
	if (particle == NULL) return;
	if (_vel == NULL) return;
	particle->vel.x = _vel->x;
	particle->vel.y = _vel->y;	
}

PVector* Particle_getSpeed (const Particle* particle) {
	if (particle == NULL) return NULL;
	PVector* pv = (PVector*) malloc( sizeof(Particle) );
	pv->x = particle->vel.x;
	pv->y = particle->vel.y;
	return pv;
}

void Particle_setAcceleration (Particle* particle, const PVector* _acc)  {
	if (particle == NULL) return;
	if (_acc == NULL) return;
	particle->acc.x = _acc->x;
	particle->acc.y = _acc->y;	
}

PVector* Particle_getAcceleration (const Particle* particle) {
	if (particle == NULL) return NULL;
	PVector* pv = (PVector*) malloc( sizeof(Particle) );
	pv->x = particle->acc.x;
	pv->y = particle->acc.y;
	return pv;
}

void Particle_updatePosition (Particle* particle, const PVector* windowData) {
	if (particle == NULL) return;	
	if (windowData == NULL) return;

	PVector_limit(&(particle->acc), 0.2);
	
	particle->vel.x += particle->acc.x;
	particle->vel.y += particle->acc.y;
	PVector_limit(&(particle->vel), 10);
	
	particle->pos.x += particle->vel.x;
	particle->pos.y += particle->vel.y;
	
	checkBorders(particle, windowData);
}

void checkBorders (Particle* particle, const PVector* windowData) {
	if (particle == NULL) return;	
	if (windowData == NULL) return;
	
	// check the x axis
	if (particle->pos.x + particle->radius > windowData->x) {
		// particle is near the right border of the window
		particle->pos.x = windowData->x - particle->radius;
		particle->vel.x *= -1;
	} else if (particle->pos.x - particle->radius < 0) {
		// particle is near the left border of the window
		particle->pos.x = 0 + particle->radius;
		particle->vel.x *= -1;
	}
	
	// check the y axis
	if (particle->pos.y + particle->radius > windowData->y) {
		// particle is near the lower border of thw window
		particle->pos.y = windowData->y - particle->radius;
		particle->vel.y *= -1;
	} else if (particle->pos.y - particle->radius < 0) {
		// particle is near the upper border of the window
		particle->pos.y = 0 + particle->radius;
		particle->vel.y *= -1;
	}
	
}

void Particle_destroy (Particle* particle) {
	if (particle == NULL) {
		return;
	}
	free(particle);
}