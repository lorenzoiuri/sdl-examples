#ifndef _UTILSH_
#define _UTILSH_

#include <stdlib.h>
#include <time.h>

/** Initializes the seed for the random number generator with the time
 */
void initRand ();

/** Generates a random number between min and max
 *  REQUIRES to have the seed already set
 */
float randf (float min, float max);

#endif