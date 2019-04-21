
#include "PVector.h"

PVector* PVector_create (float _x, float _y) {
	PVector* p = (PVector*) malloc ( sizeof(PVector) );
	p->x = _x;
	p->y = _y;
	return p; 
}

void PVector_destroy (PVector* pv) {
	if (pv == NULL) {
		return;
	}
	free(pv);
}

void PVector_limit (PVector* pv, float limitValue) {
	if (pv == NULL) return;
	if (pv->x > limitValue) {
		pv->x = limitValue;
	} 
	if (pv->y > limitValue) {
		pv->y = limitValue;
	}
}

PVector* PVector_clone (const PVector* src) {
	if ( src == NULL ) return NULL;
	
	PVector* dst = (PVector*) malloc ( sizeof(PVector) );
	dst->x = src->x;
	dst->y = src->y;
	return dst;
}


void PVector_add (PVector* src, const PVector* adding) {
	if (src == NULL) return;
	if (adding == NULL) return;
	
	src->x += adding->x;
	src->y += adding->y;
}
