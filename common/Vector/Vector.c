
#include "Vector.h"


Vector* Vector_create () {
	Vector* v = (Vector*) malloc (sizeof (Vector) );
	void** elts = (void*) malloc ( sizeof (void*) * INITIAL_SIZE );
	v->elements = elts;
	v->effectiveSize = INITIAL_SIZE;
	v->length = 0;
	return v;
}

int Vector_isEmpty ( Vector* v ) {
	if ( v == NULL ) return 0;
	if ( v->length == 0 ) return 1;
	return 0;
}

int Vector_add ( Vector* v, void* toInsert ) {
	if ( v == NULL ) return -1;
	if ( toInsert == NULL ) return -1;
	
	if ( v->length == v->effectiveSize  ) {
		v->effectiveSize *= 2;
		v->elements = realloc(v->elements, (v->effectiveSize) * sizeof(void*) );
		printf("reallocated: %d -> %d\n", (v->effectiveSize)/2, v->effectiveSize);
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

void* Vector_get ( Vector* v, int index ) {
	if ( v == NULL ) return NULL;
	int maxValidIndex = (v->length) - 1;
	if ( index < 0 || index > maxValidIndex) return NULL;
	return v->elements[index];
}

int Vector_isValidIndex ( Vector* v, int index ) {
	if ( v == NULL ) return 0;
	int maxValidIndex = (v->length) - 1;
	if ( index < 0 || index > maxValidIndex) return 0;
	return 1;
}

int Vector_remove ( Vector* v, int index, int deallocation ) {
    if ( v == NULL ) return 0;
    int maxValidIndex = (v->length) - 1;
    if ( index < 0 || index > maxValidIndex) return 0;
	
	// free the element in position index
	if ( deallocation == 1 ) {
        if (v->elements[index] != NULL) {
            free( v->elements[index] );
        }
	}
	
	// shift the elements at index > argument index back by one position
	for (int i=index+1; i<(v->length); i++) {
		v->elements[i-1] = v->elements[i];
	}
	v->elements[v->length] = NULL;
	
	// decrement the lenght
	v->length -= 1;
	
	// eventually reallocate
	if ( ((v->length) == ((v->effectiveSize)/2)) && ((v->length) > INITIAL_SIZE) ) {
		v->effectiveSize /= 2;
		v->elements = realloc(v->elements, (v->effectiveSize) * sizeof(void*) );
		printf("reallocated: %d -> %d\n", (v->effectiveSize)*2, v->effectiveSize);
	}
	
	return 1;
}

int Vector_deallocateAll (Vector* v) {
    if (v == NULL) return 0;
    for (int index=0; index<(v->length); index++) {
        if (v->elements[index] != NULL) {
            free( v->elements[index] );
        }
    }
    v->effectiveSize = INITIAL_SIZE;
    v->elements = realloc(v->elements, INITIAL_SIZE * sizeof(void*) );
    v->length = 0;
    
    return 1;
}
