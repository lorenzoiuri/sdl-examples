#include "car.h"

Car* Car_create (int _bodyWid, int _bodyHei, int _wheelRadius) {
	
	if (_bodyWid <= 0 || _bodyHei <= 0 || _wheelRadius <= 0) {
		return NULL;
	}
	Car* toReturn = (Car*) malloc ( sizeof(Car) );
	toReturn->pos.xPos = 0;
	toReturn->pos.yPos = 0;
	toReturn->bodyWid = _bodyWid;
	toReturn->bodyHei = _bodyHei;
	toReturn->wheelRadius = _wheelRadius;
	toReturn->color.r = 0;
	toReturn->color.g = 0;
	toReturn->color.b = 0;
	toReturn->color.a = 255;
	return toReturn;
}

void Car_setColor (Car* car, int _r, int _g, int _b) {
	if (_r < 0 || _r > 255) {
		return;
	}
	if (_g < 0 || _g > 255) {
		return;
	}
	if (_b < 0 || _b > 255) {
		return;
	}
	if ( car == NULL ) {
		return;
	}
	
	car->color.r = _r;
	car->color.g = _g;
	car->color.b = _b;
}

PVector* Car_getPosition (const Car* car) {
	
	if (car == NULL) {
		return NULL;
	}
	PVector* toReturn = (PVector*) malloc ( sizeof(PVector) );
	toReturn->xPos = car->pos.xPos;
	toReturn->yPos = car->pos.yPos;
	return toReturn;
}

void Car_setPosition (Car* car, const PVector* _pos) {
	if (car == NULL) {
		return;
	}
	if (_pos == NULL) {
		return;
	}
	car->pos.xPos = _pos->xPos;
	car->pos.yPos = _pos->yPos;
	
}

void Car_render (SDL_Renderer* renderer, const Car* car) {

	if (renderer == NULL) {
		return;
	}
	if (car == NULL) {
		return;
	}
	// render the body
	SDL_SetRenderDrawColor(renderer, car->color.r, car->color.g, car->color.b, car->color.a);
   SDL_Rect body = {car->pos.xPos, car->pos.yPos, car->bodyWid, car->bodyHei};
   SDL_RenderFillRect(renderer, &body);
   
   // render the wheels
   RenderFillCircle(renderer, car->pos.xPos + 0.25*car->bodyWid, car->pos.yPos + car->bodyHei, car->wheelRadius);
   RenderFillCircle(renderer, car->pos.xPos + 0.75*car->bodyWid, car->pos.yPos + car->bodyHei, car->wheelRadius);
} 

void Car_destroy (Car* car) {
	if (car == NULL) {
		return;
	}
	free(car);
}