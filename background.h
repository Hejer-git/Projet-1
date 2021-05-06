#ifndef BACKGROUND_H_INCLUDED
	#define BACKGROUND_H_INCLUDED
	
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_mixer.h>
	#include <stdlib.h>
	#include <stdio.h>

	/**	
	* @struct Background
	* @brief struct for background
	*/
	
	typedef struct 
	{
	  SDL_Rect poscam; /*!< Rectangle*/
	  SDL_Rect posbg ; /*!< Rectangle*/
	  SDL_Surface *imagebg;  /*!< Surface. */

	}background;
	
	
	void initBack(background *b);
	void afficher(background b,SDL_Surface *screen);
	void scrolling(background *b, int direction);
	
	#endif
