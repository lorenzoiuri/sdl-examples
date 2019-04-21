
#include "circle.h"

void RenderDrawCircle(SDL_Renderer *Renderer, int _x, int _y, int radius) { 
   int x = radius - 1;
   int y = 0;
   int tx = 1;
   int ty = 1;
   int err = tx - (radius << 1); // shifting bits left by 1 effectively
                                 // doubles the value. == tx - diameter
   while (x >= y) {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(Renderer, _x + x, _y - y);
      SDL_RenderDrawPoint(Renderer, _x + x, _y + y);
      SDL_RenderDrawPoint(Renderer, _x - x, _y - y);
      SDL_RenderDrawPoint(Renderer, _x - x, _y + y);
      SDL_RenderDrawPoint(Renderer, _x + y, _y - x);
      SDL_RenderDrawPoint(Renderer, _x + y, _y + x);
      SDL_RenderDrawPoint(Renderer, _x - y, _y - x);
      SDL_RenderDrawPoint(Renderer, _x - y, _y + x);
		
      if (err <= 0) {
         y++;
         err += ty;
         ty += 2;
      } else if (err > 0) {
         x--;
         tx += 2;
         err += tx - (radius << 1);
      }
   }
}

void RenderFillCircle(SDL_Renderer *Renderer, int _x, int _y, int radius) { 
   int x = radius - 1;
   int y = 0;
   int tx = 1;
   int ty = 1;
   int err = tx - (radius << 1); // shifting bits left by 1 effectively
                                 // doubles the value. == tx - diameter
   while (x >= y) {
		SDL_RenderDrawLine(Renderer, _x + x, _y - y, _x + x, _y + y);
		SDL_RenderDrawLine(Renderer, _x - x, _y - y, _x - x, _y + y);
		SDL_RenderDrawLine(Renderer, _x + y, _y - x, _x + y, _y + x);
		SDL_RenderDrawLine(Renderer, _x - y, _y - x, _x - y, _y + x);
		
      if (err <= 0) {
         y++;
         err += ty;
         ty += 2;
      } else if (err > 0) {
         x--;
         tx += 2;
         err += tx - (radius << 1);
      }
   }
}