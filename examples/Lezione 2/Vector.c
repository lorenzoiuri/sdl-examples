
#include "Vector.h"


Vector* Vector_createVector () {
	Vector* v = (Vector*) malloc (sizeof (Vector) );
	void** elts = (void*) malloc ( sizeof (void*) * INITIAL_SIZE );
	v->elements = elts;
	v->effectiveSize = INITIAL_SIZE;
	v->length = 0;
	return v;
}

int Vector_isEmpty ( Vector* v ) {
	if ( v == NULL ) return -1;
	if ( v->length == 0 ) return 1;
	return 0;
}

int Vector_add ( Vector* v, void* toInsert ) {
	if ( v == NULL ) return -1;
	if ( toInsert == NULL ) return -1;
	
	if ( v->length == v->effectiveSize  ) {
		v->effectiveSize *= 2;
		realloc(v->elements, v->effectiveSize * sizeof(void*) );
	}
	
	v->elements[v->length] = toInsert;
	v->length += 1;
	
	return 1;
	
}

int Vector_length ( Vector* v ) {
	if ( v == NULL ) return -1;
	return v->length;
}

int Vector_destroy ( Vector* v ) {
	if ( v == NULL ) return -1;
	free( v->elements );
	free( v );
	return 1;
}

void* Vector_get ( Vector* v, int index ) {return NULL;}

int Vector_isValidIndex ( Vector* v, int index ) {return 0;}

void* Vector_extract ( Vector* v, int index ) {return 0;}

