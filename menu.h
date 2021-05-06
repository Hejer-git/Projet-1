#ifndef MENU_H_
#define MENU_H_
void free_sd(Mix_Music* music,SDL_Surface* menu1,SDL_Surface* start1,SDL_Surface* start2,SDL_Surface* option1,SDL_Surface* option2,SDL_Surface* close1,SDL_Surface* close2,Mix_Chunk* son,TTF_Font *police);
void standard(SDL_Surface* ecran,SDL_Surface* menu,SDL_Rect position);
void effet(Mix_Chunk* son,SDL_Surface* ecran,SDL_Surface* menu,SDL_Rect position);
#endif
