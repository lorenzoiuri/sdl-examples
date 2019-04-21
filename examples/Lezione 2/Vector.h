
#ifndef _VECTORH_
#define _VECTORH_

#include "stdlib.h"

#define INITIAL_SIZE 5

/*  ADT for array of variabile lenght of elements in heap, each element of the vector is a pointer to something in the heap
 *  the elements of array are pointers, the elements added are not duplicated
 *  it is not allowed to insert NULL pointers
 */
 
typedef struct Vector {
	void** elements;
	int effectiveSize; // size of array
	int length; // number of inserted elements (minus the removed)
} Vector;

/** Initializes the data structeres
 */
Vector* Vector_createVector () ;

/** Checks whether the Vector is empty
 *  returns 1 if v is empty, 0 if not
 *  returns -1 if v is NULL
 */
int Vector_isEmpty ( Vector* v );

/** Inserts toInsert into v
 *  returns 1 if added
 *  returns -1 if v is NULL or if toInsert is NULL
 */
int Vector_add ( Vector* v, void* toInsert );

/** Returns the number of elements in array
 *  returns -1 if v is null
 */
int Vector_length ( Vector* v );

/** Deallocates the memory for the vector
 *  DOES NOT deallocates the memory for the inserted elements
 *  returns 1 if success, -1 if error or if v is NULL
 */
int Vector_destroy ( Vector* v );

/** Returns the position in position index
 *  returns NULL if v is NULL or if index if out of bounds
 */
void* Vector_get ( Vector* v, int index );

/** Checks whether index is a valid index of the vector
 *  returns 1 if yes, 0 if false
 */
int Vector_isValidIndex ( Vector* v, int index );

/** Removes the index elements from the vector and shifts the latters to left of one position
 *  returns the pointer to the extracted element
 *  returns NULL if v is NULL or if index is not a valid index of the vector
 */
void* Vector_extract ( Vector* v, int index );

#endif

