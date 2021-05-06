#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
int main(int argc, char *argv[])
{
    int vol=50,ver=1;
    SDL_Event event;
    Mix_Chunk *son;
    Mix_Music *music;
    int cont=1,res=1,c=1;
    SDL_Surface *ecran = NULL,*menu1 = NULL,*texteop=NULL,*texte_option1=NULL,*texte_option2=NULL,*texte_option3=NULL,*texte_option4=NULL,*logo=NULL;
    SDL_Surface *start1=NULL,*option1=NULL,*close1=NULL,*start2=NULL,*option2=NULL,*close2=NULL,*on=NULL,*return1=NULL;
    SDL_Surface *on_hold=NULL,*off_hold=NULL,*off=NULL, *menuF=NULL;
    SDL_Rect posbg,posst,posop,poscl,poson,posoff,postx,posre,postxop,postxoption1,postxoption2,postxoption3,postxoption4;
    TTF_Font *police=NULL;
    SDL_Color coul= {0,0,0},coul_sub={0,0,0},coulop={255,255,255};
	//initialisation
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("Initialisation Error!!!!%s\n",SDL_GetError());
		return 1;
	}
    ecran = SDL_SetVideoMode(794,797,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(ecran==NULL)
	{
		printf("VideoMode Error!!%s\n",SDL_GetError());
		return 1;
	}
    SDL_WM_SetCaption("Groupe Skill Up", NULL);
    menu1=SDL_LoadBMP("menu1.bmp");
	if(menu1==NULL)
		{
			printf("BACKGROUND Loading Error!! %s\n",SDL_GetError());
		}
    start1=IMG_Load("start1.png");
    if(start1==NULL)
{
printf("ERROR loading start1 %s\n",SDL_GetError());
}
option1=IMG_Load("settings1.png");
        if(option1==NULL)
                {
                        printf("ERROR loading option1 %s\n",SDL_GetError());
                }
close1=IMG_Load("close1.png");
        if(close1==NULL)
                {
                        printf("ERROR Loading close1 %s\n",SDL_GetError());
                }
start2=IMG_Load("start2.png");
	if(start2==NULL)
		{
			printf("ERROR loading start2 %s\n",SDL_GetError());
		}
option2=IMG_Load("settings2.png");
        if(option2==NULL)
                {
                        printf("ERROR loading option2 %s\n",SDL_GetError());
                }
close2=IMG_Load("close2.png");
        if(close2==NULL)
                {
                        printf("ERROR loading close2 %s\n",SDL_GetError());
                }
on=IMG_Load("on.png");
	if(on==NULL)
		{
			printf("ERROR loading sound_on %s\n",SDL_GetError());
		}
off=IMG_Load("off.png");
	if(off==NULL)
		{
			printf("ERROR loading sound_off %s\n",SDL_GetError());
		}
return1=IMG_Load("return1.png");
	if(return1==NULL)
		{
			printf("ERROR loading return1 %s\n",SDL_GetError());
		}


logo=IMG_Load("logo.png");
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadMUS("musique.mp3");
Mix_VolumeMusic(vol); 
Mix_PlayMusic(music,100);
son=Mix_LoadWAV("son.wav");
postx.x=200;
postx.y=20;
police = TTF_OpenFont("police.otf", 35);

texteop=TTF_RenderText_Blended(police, "   Game settings", coulop);
texte_option1=TTF_RenderText_Blended(police,"+ to increase sound",coulop);
texte_option2=TTF_RenderText_Blended(police,"- to decrease sound",coulop);
texte_option3=TTF_RenderText_Blended(police,"F for fullscreen mode / W for window mode",coulop);
texte_option4=TTF_RenderText_Blended(police,"Press <- to return",coulop);
    posbg.x=0;
    posbg.y=0;
    posst.x=300;
    posst.y=350;
    posop.x=300;
    posop.y=450;
    poscl.x=300;
    poscl.y=550;
    poson.x=300;
    poson.y=400;
    posoff.x=500;
    posoff.y=400;
    posre.x=10;
    posre.y=10;
    postxop.x=10;
    postxop.y=600;
    postxoption1.x=10;
    postxoption1.y=650;
    postxoption2.x=10;
    postxoption2.y=700;
    postxoption3.x=10;
    postxoption3.y=750;
    postxoption4.x=10;
    postxoption4.y=750;
    SDL_BlitSurface(menu1,NULL,ecran,&posbg);
    SDL_BlitSurface(start1,NULL,ecran, &posst);
    SDL_BlitSurface(option1,NULL,ecran, &posop);
    SDL_BlitSurface(close1,NULL,ecran, &poscl);
    SDL_Flip(ecran);
	//event&boucle du jeu
while(cont)
{
	if(res==1)
	SDL_BlitSurface(logo,NULL,ecran, &postx);
	SDL_WaitEvent(&event);
        switch(event.type)
        {
		case SDL_QUIT:
			cont=0;
			break;
		case SDL_MOUSEMOTION:
			if(((event.motion.x>=posst.x)&&(event.motion.x<=(posst.x)+222))&&((event.motion.y>=posst.y)&&(event.motion.y<=(posst.y)+78)))
			{if((res==1)&&(ver!=0)){
				effet(son,ecran,start2,posst);
			}}
			else
			{if((res==1)&&(ver!=0)){
				standard(ecran,start1,posst);
			}}
			if(((event.motion.x>=posop.x)&&(event.motion.x<=(posop.x)+219))&&((event.motion.y>=posop.y)&&(event.motion.y<=(posop.y)+74)))
                        {if((res==1)&&(ver!=0))
				{
                               	effet(son,ecran,option2,posop);
                        }}
                        else
                        {if((res==1)&&(ver!=0)){
                               standard(ecran,option1,posop);
			}}
			if(((event.motion.x>=poscl.x)&&(event.motion.x<=(poscl.x)+222))&&((event.motion.y>=poscl.y)&&(event.motion.y<=(poscl.y)+77)))
                        {if((res==1)&&(ver!=0)){
                                effet(son,ecran,close2,poscl);
			}}
	               else
                        {if((res==1)&&(ver!=0)){
                                standard(ecran,close1,poscl);
			}}
			break;
		case SDL_MOUSEBUTTONUP:
			if(((event.button.x>=poscl.x)&&(event.button.x<=(poscl.x)+222))&&((event.button.y>=poscl.y)&&(event.button.y<=(poscl.y)+77)))
				{	 //free
					if(res==1)
					{ cont=0;
					 free_sd( music, menu1, start1, start2, option1, option2, close1, close2, son,police);
				}}
			else if(((event.button.x>=posop.x)&&(event.button.x<=(posop.x)+219))&&((event.button.y>=posop.y)&&(event.button.y<=(posop.y)+74)))
				{	res=0;
					SDL_BlitSurface(menu1,NULL,ecran,&posbg);
					SDL_BlitSurface(return1,NULL,ecran,&posre);	
					SDL_BlitSurface(on,NULL,ecran,&poson);
					SDL_BlitSurface(off, NULL,ecran, &posoff);
					SDL_BlitSurface(texteop,NULL,ecran,&postxop);
					SDL_BlitSurface(texte_option1,NULL,ecran,&postxoption1);
					SDL_BlitSurface(texte_option2,NULL,ecran,&postxoption2);
					SDL_BlitSurface(texte_option3,NULL,ecran,&postxoption3);
					SDL_Flip(ecran);
				}
			else  if(((event.button.x>=posoff.x)&&(event.button.x<=(posoff.x)+55))&&((event.button.y>=posoff.y)&&(event.button.y<=(posoff.y)+57)))
                                                {if(res==0)
                                                        {Mix_PauseMusic();}
                                                }
			 else  if(((event.button.x>=poson.x)&&(event.button.x<=(poson.x)+56))&&((event.button.y>=poson.y)&&(event.button.y<=(poson.y)+58)))
                                                {if(res==0)
                                                        {Mix_ResumeMusic();}
                                                }
			else if(((event.button.x>=posre.x)&&(event.button.x<=(posre.x)+222))&&((event.button.y>=posre.y)&&(event.button.y<=(posre.y)+8)))
						{if(res==0)
							{SDL_BlitSurface(menu1,NULL,ecran,&posbg);
							SDL_BlitSurface(start1,NULL,ecran, &posst);
   							SDL_BlitSurface(option1,NULL,ecran, &posop);
  							SDL_BlitSurface(close1,NULL,ecran, &poscl);

							res=1;
						}}
			else if(((event.button.x>=posst.x)&&(event.button.x<=(posst.x)+222))&&((event.button.y>=posst.y)&&(event.button.y<=(posst.y)+78)))
						{if(res==1)
							ver=0;
							SDL_BlitSurface(menu1,NULL,ecran,&posbg);
							SDL_BlitSurface(texte_option4,NULL,ecran,&postxoption4);
							SDL_Flip(ecran);
						}
			
				break;
		 case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_LEFT:///retour vers main menu avec fleche gauche
                    	SDL_BlitSurface(menu1,NULL,ecran,&posbg);
			SDL_BlitSurface(start1,NULL,ecran, &posst);
   			SDL_BlitSurface(option1,NULL,ecran, &posop);
  			SDL_BlitSurface(close1,NULL,ecran, &poscl);
			//SDL_BlitSurface(texte_main,NULL,ecran,&postx);
			res=1;
			ver=1;
			SDL_Flip(ecran);
			break;
		case SDLK_f:///mode fullscreen
			ecran = SDL_SetVideoMode(1196,796,32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
			if((res==1)&&(ver!=0))///fullscreen main menu
			{
				SDL_BlitSurface(menu1,NULL,ecran,&posbg);
				SDL_BlitSurface(start1,NULL,ecran, &posst);
   				SDL_BlitSurface(option1,NULL,ecran, &posop);
  				SDL_BlitSurface(close1,NULL,ecran, &poscl);

				SDL_Flip(ecran);
			}
			else if(ver==0)
			{
				SDL_BlitSurface(menu1,NULL,ecran,&posbg);
				SDL_BlitSurface(texte_option4,NULL,ecran,&postxoption4);
				SDL_Flip(ecran);
				
			}
			else if(res==0)///fullscreen options menu
			{
				SDL_BlitSurface(menu1,NULL,ecran,&posbg);
				SDL_BlitSurface(return1,NULL,ecran,&posre);	
				SDL_BlitSurface(on,NULL,ecran,&poson);
				SDL_BlitSurface(off, NULL,ecran, &posoff);
				SDL_BlitSurface(texteop,NULL,ecran,&postxop);
				SDL_BlitSurface(texte_option1,NULL,ecran,&postxoption1);
				SDL_BlitSurface(texte_option2,NULL,ecran,&postxoption2);
				SDL_BlitSurface(texte_option3,NULL,ecran,&postxoption3);
				SDL_Flip(ecran);
			}
			break;
		case SDLK_w:///window mode
			ecran = SDL_SetVideoMode(1196,796,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
			if((res==1)&&(ver!=0))
			{
				SDL_BlitSurface(menu1,NULL,ecran,&posbg);
				SDL_BlitSurface(start1,NULL,ecran, &posst);
   				SDL_BlitSurface(option1,NULL,ecran, &posop);
  				SDL_BlitSurface(close1,NULL,ecran, &poscl);

				SDL_Flip(ecran);
			}
			else if(ver==0)
			{
				SDL_BlitSurface(menu1,NULL,ecran,&posbg);
				SDL_BlitSurface(texte_option4,NULL,ecran,&postxoption4);
				SDL_Flip(ecran);
				
			}
			else if(res==0)
			{
				SDL_BlitSurface(menu1,NULL,ecran,&posbg);
				SDL_BlitSurface(return1,NULL,ecran,&posre);	
				SDL_BlitSurface(on,NULL,ecran,&poson);
				SDL_BlitSurface(off, NULL,ecran, &posoff);
				SDL_BlitSurface(texteop,NULL,ecran,&postxop);
				SDL_BlitSurface(texteop,NULL,ecran,&postxop);
				SDL_BlitSurface(texte_option1,NULL,ecran,&postxoption1);
				SDL_BlitSurface(texte_option2,NULL,ecran,&postxoption2);
				SDL_BlitSurface(texte_option3,NULL,ecran,&postxoption3);
				SDL_Flip(ecran);
			}
			break;
		case SDLK_KP_PLUS:///augmenter le volume avec la touche +
			if(vol<125)
			{
				vol=vol+25;
			}
		Mix_VolumeMusic(vol);
		break;
		case SDLK_KP_MINUS:///diminuer le volume avec la touche -
			if(vol>0)
			{
				vol=vol-25;
			}	
		Mix_VolumeMusic(vol);
		break;
		     }
}
}
	return EXIT_SUCCESS;

}
