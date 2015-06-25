/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Thu Jun 25 17:42:39 2015 Kevin Costa
*/

#include	<SDL2/SDL.h>

void input(void)
{
  SDL_Event event;
  int a;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	a = 0; /* QUITTER */
      if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_SPACE)
	    a = 0; /* CHECK CASE */
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    a = 0; /* QUITTER */
	  if (event.key.keysym.sym == SDLK_UP)
	    a = 0; /* HAUT */
	  if (event.key.keysym.sym == SDLK_DOWN)
	    a = 0; /* BAS */
	  if (event.key.keysym.sym == SDLK_LEFT)
	    a = 0; /* DROITE */
	  if (event.key.keysym.sym == SDLK_RIGHT)
	    a = 0; /* GAUCHE */
	  if (event.key.keysym.sym == SDLK_R)
	    a = 0; /* reset camera pos initial */
	  if (event.key.keysym.sym == SDLK_SPACE)
	    a = 0; /* CHECK CASE */
	  if (event.key.keysym.sym == SDLK_KP_MINUS)
	    a = 0; /* ZOOM - */
	  if (event.key.keysym.sym == SDLK_KP_PLUS)
	    a = 0; /* ZOOM + */
	}
    }
}
