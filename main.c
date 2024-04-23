#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "joueur.h"

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 769

SDL_Surface *screen = NULL;
SDL_Surface *bg = NULL;

void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        exit(1);
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Failed to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
}

void closeSDL() {
    SDL_FreeSurface(bg); 
    SDL_Quit();
}

int main() {
    initSDL();


    bg = IMG_Load("bg.jpg");
    if (bg == NULL) {
        fprintf(stderr, "Failed to load background image: %s\n", IMG_GetError());
        closeSDL(); 
        return 1;
    }

   
    Personne joueur1;
    init(&joueur1);

    Uint32 t_prev = SDL_GetTicks();
    Uint32 dt = 0;

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        joueur1.acceleration += 0.005;
                        break;
                    case SDLK_DOWN:
                        joueur1.acceleration -= 0.01;
                        break;
                    default:
                        break;
                }
            }
        }

        dt = SDL_GetTicks() - t_prev;
        t_prev = SDL_GetTicks();

        movePerso(&joueur1, dt);


        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

  
        SDL_BlitSurface(bg, NULL, screen, NULL);

 
        afficheperso(screen, &joueur1);


        SDL_Flip(screen);
    }

    closeSDL();

    return 0;
}
