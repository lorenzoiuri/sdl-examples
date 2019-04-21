
#include "utils.h"

float randf (float min, float max) {
	float rnd =  rand() / (float) RAND_MAX;
	return min + rnd * (max-min);
}

void initRand () {
	srand(time(NULL));
}