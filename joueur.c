#include "joueur.h"

void init(Personne *p) {    
p->sprite = IMG_Load("bg.jpg");
    if (p->sprite == NULL) {
        fprintf(stderr, "unable to load sprite image %s \n", IMG_GetError());
        exit(1);
    }

    p->frame.x = 0;
    p->frame.y = 0;
    p->frame.h = 420 / 6;
    p->frame.w = 640 / 8;

    p->posScreen.x = 0;
    p->posScreen.y = 450;
    p->posScreen.w = 640;
    p->posScreen.h = 420;

    p->up = 0;
    p->v0 = 60;
    p->a = 2;
    p->vx = 3;
    p->vgrav = 0.3;
    p->vsaut = -6.5;
    p->vy = p->vsaut;
    p->vitesse = 0;
}

void afficheperso(SDL_Surface *screen, Personne *p) {
    SDL_BlitSurface(p->sprite, &p->frame, screen, &p->posScreen);
}

void saut(Personne *p, int posinit, int dt) {
    if (p->up == 1) {
        p->posScreen.x += p->vx * dt;
        p->posScreen.y = (-0.04 * (p->posScreen.x - posinit) * (p->posScreen.x - posinit)) + posinit;
        if (p->posScreen.y >= posinit) {
            p->up = 0;
            p->posScreen.y = posinit;
        }
    }
}

void movePerso(Personne *p, Uint32 dt) {
    p->vitesse += p->acceleration * dt / 1000.0;
    if (p->vitesse < 0) {
        p->vitesse = 0;
    }

    double dx = p->vitesse * dt / 1000.0;
    p->posScreen.x += dx;

    p->acceleration = 0;
}




void animerPerso(Personne *p) {

    if (p->direction < 0 || p->direction > 3) {
        p->direction = 0; 
    }

   
    p->posSPRITE.y = p->direction * p->posSPRITE.h;
    p->posSPRITE.x = p->posSPRITE.x + p->posSPRITE.w;


    if (p->up == 1) {
        p->posSPRITE.x = 0;
    } else {
        if (p->posSPRITE.x >= (354 - p->posSPRITE.w)) {
            p->posSPRITE.x = 0;
        }
    }
}
