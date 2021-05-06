/**	
	* @file background.c
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
	

/**	
	* @brief To initialize the background b .
	* @param b the background
	* @return Nothing
*/
	void initBack(background *b)
	{
	  b->imagebg = SDL_LoadBMP("level1.bmp");
	  b->poscam.x = 0;
	  b->poscam.y = 0;
	  b->poscam.w = 640;
	  b->poscam.h = 480;
	  b->posbg.x = 0;
	  b->posbg.y = 0;
	  b->posbg.w = b->imagebg->w;
	  b->posbg.h = b->imagebg->h;
	}
	
/**	
	* @brief To show the background b .
	* @param b the background
	* @param screen the screen 
	* @return Nothing
*/
	void afficher(background b,SDL_Surface *screen)
	{
	  SDL_BlitSurface(b.imagebg,&b.poscam,screen,&b.posbg);
	}
	
/**	
	* @brief To scroll the background b .
	* @param b the background
	* @param direction the direction
	* @return Nothing
*/
	void scrolling(background *b, int direction)
	{ const int speed=5;
 	  int x,y;
          x = 0;
          y = 0;
	  if(direction != -1)
	{
	  if(direction == 0)
	  {
	    b->poscam.x+=10;
	  }
	  if(direction == 1)
	  {
	    b->poscam.x-=10;
	  }
	  if(direction == 2)
	  {
	    b->poscam.y-=0;
	  }
	  if(direction == 3)
	  {
	    b->poscam.y+=0;
	  }

	  if(direction == 0)
            {
                x += speed;
               b->poscam.x += speed;
                if(b->poscam.x >= 1500-640)
                    b->poscam.x = 0;
            }
	  if(direction == 1)
            {
                x -= speed;
                b->poscam.x -= speed;
                if(b->poscam.x <= 0)
                    b->poscam.x = 1500-640;
            }
	  if(direction == 2)
            {
                y += speed;
                b->poscam.y += speed;
                if(b->poscam.y >= 500-480)
                    b->poscam.y = 0;
            }
	  if(direction == 3)
            {
                y -= speed;
                b->poscam.y -= speed;
                if(b->poscam.y <= 0)
                    b->poscam.y = 500-480;
            }
     }
	  
}
	
	

