#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<time.h> 
#include"ES.h"
#include <math.h> 
 

const int LARGEUR_SPRITE= 474;
const int HAUTEUR_SPRITE= 105;

void initEnnemi(Ennemi*e)
{
const int A=60,B=600;
srand(time(NULL));

e->spritesheet = IMG_Load("spritesheet ennemi.png"); //chargement du sprite sheet

//les posisiton de l'ennemi sur l'écran
e->posennemi.y=350;
e->posennemi.x=(rand() % (B - A + 1)) +A ;

//le clip initial
e->possprite.x=0;
e->possprite.y=0;
e->possprite.w=79;
e->possprite.h=105;

//la direction initial
e->direction=0;

}

void afficherEnnemi(Ennemi e, SDL_Surface* screen)
{
SDL_BlitSurface( e.spritesheet , &e.possprite , screen , &e.posennemi );
SDL_Flip(screen);
}
void animerEnnemi( Ennemi * e)
{

if(e->direction == 0)
   e->possprite.y= 0; 
else
   e->possprite.y= 102; 

if(e->possprite.x == LARGEUR_SPRITE -79) 
   e->possprite.x=0; 
else
   e->possprite.x += 79; 

}
void deplacer( Ennemi * e)
{
if( e->posennemi.x > 600 )
 e->direction = 1;
if( e->posennemi.x < 60 )
 e->direction = 0;

if( e->direction == 0)
  e->posennemi.x+=2;
else
  e->posennemi.x-=2;

}
int collisionBB( personne p, Ennemi e) 
{
if(( (p.posperso.x + p.possprite_perso.w)< e.posennemi.x ) || (e.posennemi.x + e.possprite.w < p.posperso.x ) )
return 0;
else
return 1;

} 

void init_personnage(personne* p)
{ 

p->sprite_perso = IMG_Load("sherif1.PNG"); 

p->posperso.x= 600;
p->posperso.y= 320;

//le clip à afficher
p->possprite_perso.x=0;
p->possprite_perso.y=0;
p->possprite_perso.w=395;
p->possprite_perso.h=488;

p->direction_perso=0;


}


void afficher_personnage(personne p, SDL_Surface * screen)
{
SDL_BlitSurface( p.sprite_perso , &p.possprite_perso , screen , &p.posperso );
SDL_Flip(screen);
}
/*
void deplacerIA( Ennemi * e)
{
}
*/
