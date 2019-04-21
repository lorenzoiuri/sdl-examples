#include "SDL_utils.h"

PVector* PVector_create (float _x, float _y) {
	PVector* p = (PVector*) malloc ( sizeof(PVector) );
	p->xPos = _x;
	p->yPos = _y;
	return p; 
}

void PVector_destroy (PVector* _pv) {
	if (_pv == NULL) {
		return;
	}
	free(_pv);
}
