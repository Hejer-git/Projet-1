#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
void free_sd(Mix_Music* music,SDL_Surface* menu1,SDL_Surface* start1,SDL_Surface* start2,SDL_Surface* option1,SDL_Surface* option2,SDL_Surface* close1,SDL_Surface* close2,Mix_Chunk* son,TTF_Font *police)
{	
   	SDL_FreeSurface(menu1);
   	SDL_FreeSurface(start1);
   	SDL_FreeSurface(start2);
	SDL_FreeSurface(option1);
	SDL_FreeSurface(option2);
	SDL_FreeSurface(close1);
	SDL_FreeSurface(close2);
   	Mix_FreeMusic(music);
   	Mix_FreeChunk(son);
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_Quit();
}
void standard(SDL_Surface* ecran,SDL_Surface* menu1,SDL_Rect position)
{
	SDL_BlitSurface(menu1,NULL,ecran,&position);
       	SDL_Flip(ecran);
}

void effet(Mix_Chunk* son,SDL_Surface* ecran,SDL_Surface* menu1,SDL_Rect position)
{
	SDL_BlitSurface(menu1,NULL,ecran,&position);
	Mix_PlayChannel(0,son,0);
	SDL_Flip(ecran);
}
