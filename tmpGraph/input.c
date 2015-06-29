/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Fri Jun 26 14:43:24 2015 Kevin Costa
*/

#include	<SDL2/SDL.h>

void input(void)
{
  SDL_Event event;
  int a;
  int x;
  int y;

  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  exit(1); /* quitter */
	case SDL_MOUSEBUTTONDOWN:
	  x = event.button.x;
	  y = event.button.y;
	case SDL_KEYDOWN:
	  switch (event.key.keysym.scancode)
	    {
	    case SDL_SCANCODE_ESCAPE:
	      exit(1); /* quitter */
	    case SDL_SCANCODE_UP:
	      a = 0; /* HAUT */
	    case SDL_SCANCODE_DOWN:
	      a = 0; /* BAS */
	    case SDL_SCANCODE_RIGHT:
	      a = 0; /* GAUCHE */
	    case SDL_SCANCODE_LEFT:
	      a = 0; /* DROITE */
	    case SDL_SCANCODE_KP_PLUS:
	      a = 0; /* ZOOM + */
	    case SDL_SCANCODE_KP_MINUS:
	      a = 0; /* ZOOM - */
	    case SDL_SCANCODE_R:
	      a = 0; /* reset cam */
	    }
	}
    }
}
