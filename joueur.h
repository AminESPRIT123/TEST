#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#define SCREEN_H 600
#define SCREEN_W 1000

typedef struct {
    SDL_Surface *sprite;
    SDL_Rect frame;
    SDL_Rect posScreen;
    int up;
    int v0;
    int a;
    int vx;
    float vgrav;
    float vsaut;
    float vy;
    double acceleration;
    double vitesse;
    int direction;
    SDL_Rect posSPRITE; 
} Personne;



void init(Personne *p); 
void afficheperso(SDL_Surface *screen, Personne *p);
void movePerso(Personne *p, Uint32 dt);
void animerPerso(Personne *p);
void saut(Personne *p, int posinit, int dt);

#endif
