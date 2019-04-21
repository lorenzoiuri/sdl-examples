
#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct thing {
	int fst;
	double snd;
} thing;

int main () {
	
	Vector* v = Vector_create();
	for (int i=0; i<7; i++) {
		thing* t = (thing*) malloc( sizeof( thing ) );
		t->fst = (i+1)*10;
		t->snd = (i+1)*10 + (i+1)*0.1;
		Vector_add(v, t);
	}
	printf("length: %d\n", v->length);
    	
	Vector_remove(v, 2, 1);
	Vector_remove(v, 2, 1);
	Vector_remove(v, 4, 1);
	
	for (int i=0; i<(v->length); i++) {
		thing* t = Vector_get(v, i);
		int fst = t->fst;
		double snd = t->snd;
		printf("index=%d, %d\n", i, fst);
	}
    
    Vector_deallocateAll(v);
	Vector_destroy(v);
	
	return 0;
}
