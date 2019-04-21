
#include "Shooter.h"


Shooter* Shooter_createShooter(int _x, int _y) {
    
    Shooter* sh = (Shooter*) malloc( sizeof(Shooter) );
    sh->pos = PVector_create(_x, _y);
    sh->color = (int*) malloc( COLOR_COMPONENTS * sizeof(int) );
    sh->color[0] = 0; sh->color[1] = 0; sh->color[2] = 0;
    sh->facing = 'r';
    return sh;
}

void Shooter_renderShooter(SDL_Renderer renderer, Shooter* sh) {
    
    if (sh == NULL) return;
    
    SDL_SetRenderDrawColor(renderer, sh->color[0], sh->color[1], sh->color[2], 255);
    
    SDL_Rect body = {sh->pos.xPos, sh->pos.yPos, 10, 30};
    SDL_RenderFillRect(renderer, &body);

    
    
}
