#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
int main()
{
   
Personne p,p1;
SDL_Surface *screen;
SDL_Surface *back;
int continuer=1;
SDL_Event event;
int acceleration=0;
int deceleration=0;

Uint32 t_prev,t_fin , dt ;//unsigned int
/*
    t_prev : temps de debut de boucle
    t_fin : temps de fin de boucle
    dt : t_fin - t_prev
*/


SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode (1500,500,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
initPerso(&p);


back=IMG_Load("back.png");



while (continuer)
{
t_prev = SDL_GetTicks();

while(SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
    continuer=0;
    break;

case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case  SDLK_RIGHT:
        p.direction=0;
        p.vitesse=5;

deplacerPerso(&p,dt);
animerPerso(&p);
        break;
    case  SDLK_LEFT:
        p.direction=1;
        p.vitesse=5;

deplacerPerso(&p,dt);
animerPerso(&p);
        break;
   /* case SDLK_UP:
        p.up=1;
saut(&p);
        break;  */
    case SDLK_p:
        acceleration=1;
    break;
    case SDLK_o:
        deceleration=1;
        break;

       
    }
break;

case SDL_KEYUP:
switch (event.key.keysym.sym)
    {
    case  SDLK_RIGHT:
              p.vitesse=0;
        break;

    case  SDLK_LEFT:        
        p.vitesse=0;
        break;

    /*case SDLK_UP:
        p.up=0;
        break;*/

   case SDLK_p:
        acceleration=0;
    break;

    case SDLK_o:
        deceleration=0;
        break;



        case  SDLK_d:
              p1.vitesse=0;
        break;

   
    }

break;
}
}
if (acceleration==1) 
{p.acceleration = p.acceleration + 0.005 ;}
if (deceleration==1) 
{p.acceleration = p.acceleration - 0.01;}

p.acceleration = p.acceleration - 0.001;//accelereration diminue sans condition prealabe (atelier)
if (p.acceleration<0) p.acceleration =0;


p1.acceleration = p1.acceleration - 0.001;//accelereration diminue sans condition prealabe (atelier)



SDL_Delay(3);
t_fin=SDL_GetTicks();
dt=t_fin - t_prev ;



SDL_BlitSurface(back,NULL,screen,NULL);
afficherPerso(p,screen);
//afficherPerso(p1,screen);
SDL_Flip(screen);

SDL_Delay(30);
}


    return 0;
}

