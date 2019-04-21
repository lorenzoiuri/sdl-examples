#ifndef _PVECTORH_
#define _PVECTORH_

#include <stdlib.h>

typedef struct PVector {
	float x;
	float y;
} PVector;

PVector* PVector_create (float _x, float _y);

void PVector_destroy (PVector* _pv);

/** Limits every component of the vector to limitValue
 */
void PVector_limit (PVector* _pv, float limitValue);

/** Creates a new PVector with the components of src
 *  does not modify src
 */
PVector* PVector_clone (const PVector* src);

/* Adds adding to src, MODIFY src
 */
void PVector_add (PVector* src, const PVector* adding);

#endif