
#ifndef _VECTORH_
#define _VECTORH_

#include <stdlib.h>
#include <stdio.h> // toremove

#define INITIAL_SIZE 2

/*  ADT for array of variabile lenght of elements in heap, each element of the vector is a pointer to something in the heap
 *  the elements of array are pointers, the elements added are not duplicated
 *  it is not allowed to insert NULL pointers
 */
 
typedef struct Vector {
	void** elements;
	int effectiveSize; // size of array in memory (in number of elements)
	int length; // number of logical elements in the array
} Vector;

/** Initializes the data structeres
 */
Vector* Vector_create () ;

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

/** Returns the element in position index
 *  returns NULL if v is NULL or if index if out of bounds
 */
void* Vector_get ( Vector* v, int index );

/** Checks whether index is a valid index of the vector
 *  returns 1 if yes, 0 if false
 */
int Vector_isValidIndex ( Vector* v, int index );

/** Removes the index elements from the vector and shifts the latters to left of one position
 *  if deallocation == 1 then the element in position index is dellocated
 *  returns 1 if success, 0 otherwise
 *  returns 0 if v is NULL or if index is not a valid index of the vector
 */
int Vector_remove ( Vector* v, int index, int deallocation );

/** Deallocates every non-null element in the array
 *  returns 1 if success, 0 otherwise
 *  returns 0 if v is null
 *  empties the array, after calling the procedure the array will be of size 0
 *  DOES NOT deallocates the array, only its elements
 */
int Vector_deallocateAll (Vector* v);

#endif

