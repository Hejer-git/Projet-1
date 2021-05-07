
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
void initPerso(Personne *p){

    p->acceleration=0;
    p->direction=0;
    p->num=0;
    p->up=0;
    p->position.x=60;
    p->position.y=370;

    p->vitesse=0;
    p->vitesse_saut=0;
p->images[0][0]=IMG_Load("droite1.png");
p->images[0][1]=IMG_Load("droite2.png");
p->images[0][2]=IMG_Load("droite3.png");
p->images[0][3]=IMG_Load("droite4.png");
p->images[1][0]=IMG_Load("gauche1.png");
p->images[1][1]=IMG_Load("gauche2.png");
p->images[1][2]=IMG_Load("gauche3.png");
p->images[1][3]=IMG_Load("gauche4.png");
p->imageActuel=p->images[0][0];
 
}


void afficherPerso(Personne p, SDL_Surface * screen){
 SDL_BlitSurface(p.imageActuel,NULL,screen,&p.position);
}



void animerPerso (Personne* p)
{
    if (p->num >= 4)
      p->num=0;
    else {
      p->num++;
    }
 if ((p->vitesse==0) && ((p->direction == 0) || (p->direction == 1)))
    {
       p->num= 0;
    }
p->imageActuel=p->images[p->direction][p->num];
}




void deplacerPerso (Personne *p,int dt){

double dx;
dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
    if (p->direction==0)     //droite
    {
        p->position.x +=  dx ;        
    }
else if (p->direction==1)   //gauche
    {
        p->position.x -=  dx;
    }
   
}
