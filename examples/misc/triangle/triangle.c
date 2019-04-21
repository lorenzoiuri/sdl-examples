
#include "triangle.h"

double my_abs( double src ) {
	if (src >= 0) {
		return src;
	} else {
		return src*-1;
	}
}

double my_max( double n1, double n2, double n3, double n4) {
	double currentMax = n1;
	if (n2 > currentMax) {
		currentMax = n2;
	}
	if (n3 > currentMax) {
		currentMax = n3;
	}
	if (n4 > currentMax) {
		currentMax = n4;
	}
	return currentMax;
}

double my_min( double n1, double n2, double n3, double n4) {
	double currentMin = n1;
	if (n2 < currentMin) {
		currentMin = n2;
	}
	if (n3 < currentMin) {
		currentMin = n3;
	}
	if (n4 < currentMin) {
		currentMin = n4;
	}
	return currentMin;
}

int my_sign(int n) {
	if (n>=0) return 1;
	else return -1;
}

void RenderDrawIsoTriangle(SDL_Renderer *Renderer, int _x, int _y, int base, int hei) {
	
	SDL_RenderDrawLine(Renderer, _x, _y - hei/2, _x - base/2, _y + hei/2);
	SDL_RenderDrawLine(Renderer, _x - base/2, _y + hei/2, _x + base/2, _y + hei/2);
	SDL_RenderDrawLine(Renderer, _x + base/2, _y + hei/2, _x, _y - hei/2);
}

void RenderFillIsoTriangle(SDL_Renderer *Renderer, int _x, int _y, int base, int hei) {
	
	// edges
	float v1[2] = {_x, _y-hei/2};
	float v2[2] = {_x-base/2, _y+hei/2};
	float v3[2] = {_x+base/2, _y+hei/2};
	
	// pushing right v2 and pushing left v3 towards the height of the triangle
	for (int i=hei; i>0; i--) {
		SDL_RenderDrawLine(Renderer, v2[0], v2[1], v3[0], v3[1]);
		float deltax = (base/2.0) / hei;
		v2[0] += deltax;
		v3[0] -= deltax;
		v2[1] --;
		v3[1] --;
	}
}

void RenderDrawTriangle(SDL_Renderer *Renderer, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) {
	
	SDL_RenderDrawLine(Renderer, _x1, _y1, _x2, _y2);
	SDL_RenderDrawLine(Renderer, _x2, _y2, _x3, _y3);
	SDL_RenderDrawLine(Renderer, _x3, _y3, _x1, _y1);

}

void RenderFillTriangle(SDL_Renderer *Renderer, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) {
	double v1[2] = {_x1, _y1};
	double v2[2] = {_x2, _y2};
	double v3[2] = {_x3, _y3};
	
	double delta1x = my_abs(v3[0]-v1[0]);
	double delta1y = my_abs(v3[1]-v1[1]);
	double delta2x = my_abs(v3[0]-v2[0]);
	double delta2y = my_abs(v3[1]-v2[1]);
	
	double maxValue = my_max( delta1x, delta1y, delta2x, delta2y);
	//printf("maxValue: %f\n", maxValue);
	
	double incr1x = (v3[0]-v1[0])/maxValue;
	double incr1y = (v3[1]-v1[1])/maxValue;
	double incr2x = (v3[0]-v2[0])/maxValue;
	double incr2y = (v3[1]-v2[1])/maxValue;
	
	for (int i=0; i<=maxValue; i++) {
		//printf("%d) v1: %f, %f --- v2: %f, %f --- v3: %f, %f\n", i, v1[0], v1[1], v2[0], v2[1], v3[0], v3[1]);
		SDL_RenderDrawLine(Renderer, v1[0], v1[1], v2[0], v2[1]);
		v1[0] += incr1x;
		v1[1] += incr1y;
		v2[0] += incr2x;
		v2[1] += incr2y;
	}
}

/*
void RenderFillTriangle(SDL_Renderer *Renderer, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) {
	double v1a[2] = {_x1, _y1};
	double v1b[2] = {_x1, _y1};
	double v2[2] = {_x2, _y2};
	double v3[2] = {_x3, _y3};
	
	double delta1ax = my_abs(v2[0]-v1a[0]);
	double delta1ay = my_abs(v2[1]-v1a[1]);
	double delta1bx = my_abs(v3[0]-v1b[0]);
	double delta1by = my_abs(v3[1]-v1b[1]);
	...
}
*/
