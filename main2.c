#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <math.h> 
#include"ES.h"


int main(int argc, char* argv[])
{

Ennemi e;
personne p;

SDL_Surface *screen=NULL,*arriere_plan=NULL;
SDL_Rect pos_arriere_plan;
pos_arriere_plan.x=0;
pos_arriere_plan.y=0;

	SDL_Event event;
 int continuer = 1;

SDL_Init(SDL_INIT_VIDEO);    
screen =SDL_SetVideoMode(1500,500,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);

arriere_plan= IMG_Load("level1.png");
	
	initEnnemi(&e);  
        init_personnage(&p); //initialiser le personnage
  
   while (continuer) 
   {
   	
	SDL_BlitSurface(arriere_plan, NULL, screen,&pos_arriere_plan);
        afficher_personnage(p,screen);
	afficherEnnemi(e,screen);
//tester la collision
         if(collisionBB(p,e))
         {
          p.posperso.y=0;
	  p.posperso.y=0;
            
         }
        while (SDL_PollEvent(&event)); 
       {
         
       switch(event.type) 

        {

           case SDL_QUIT: 

               continuer = 0; 

               break;

        }

      }
     deplacer(&e);
     animerEnnemi(&e);
     SDL_Delay(80);
  
   
    
   }
SDL_FreeSurface(e.spritesheet);
SDL_FreeSurface(p.sprite_perso);

SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).


 return EXIT_SUCCESS;  // Fermeture du programme
}

