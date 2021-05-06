/**
	* @file main.c
	* @brief Testing Program
	* @author C team
	* @version 0.1
	* @date Apr 23, 2021
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "background.h"


    int main(int argc, char** argv)
    {
	background b;
        SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event event;
        SDL_Surface *screen;
        Mix_Music *music;
	int direction, running=1;
	        Uint32 start;
	 const int FPS = 30;
        //screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
        screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_FULLSCREEN);

     if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		printf("%s",Mix_GetError());
	}

	music=Mix_LoadMUS("musique.mp3");
	Mix_PlayMusic(music,-1);

	initBack(&b);

        while(running) 
{
            start = SDL_GetTicks();
            SDL_Event event;
            while(SDL_PollEvent(&event))
 	{
scrolling(&b,direction);
                switch(event.type) 
		{
                    case SDL_QUIT:
                        running = 0;
                        break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_RIGHT:
			direction = 0;
			scrolling(&b,direction);
                                break;
                            case SDLK_LEFT:
			direction = 1;
			scrolling(&b,direction);
                                break;
                            case SDLK_UP:
			direction = 2;
			scrolling(&b,direction);
                                break;
                            case SDLK_DOWN:
			direction = 3;
			scrolling(&b,direction);
                                break;
                            case SDLK_ESCAPE:
                                running = 0;
                                break;
                        }
		   /*case SDL_KEYUP:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_RIGHT:
			direction = 0;
			//scrolling(&b,direction);
                                break;
                            case SDLK_LEFT:
			direction = 1;
			//scrolling(&b,direction);
                                break;
			    case SDLK_UP:
			direction = 3;
			//scrolling(&b,direction);
                                break;
                            case SDLK_DOWN:
			direction = 2;
			//scrolling(&b,direction);
                                break;
                        }
                        break;*/
		}
}

afficher(b,screen);
SDL_Flip(screen);
 if(1000/FPS > SDL_GetTicks()-start)
 {
                SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
 }
}

        SDL_Quit();
        return 0;
    }
