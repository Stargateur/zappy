/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Tue Jun 30 15:06:41 2015 Kevin Costa
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"

int input(t_map map, t_texture text, SDL_Renderer *renderer)
{
  SDL_Event event;
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
	  if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
	    {
	      draw_stone(&map, &text, renderer); /* GAUCHE */
	      return (1);
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
	    {
	      draw_stone(&map, &text, renderer); /* GAUCHE */
	      return (1);
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_UP)
	    {
	      draw_stone(&map, &text, renderer); /* GAUCHE */
	      return (1);
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
	    {
	      draw_stone(&map, &text, renderer); /* GAUCHE */
	      return (1);
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
	    exit(1); /* quitter */
	    /* case SDL_SCANCODE_KP_PLUS: */
	    /*   a = 0; /\* ZOOM + *\/ */
	    /* case SDL_SCANCODE_KP_MINUS: */
	    /*   a = 0; /\* ZOOM - *\/ */
	    /* case SDL_SCANCODE_R: */
	    /*   a = 0; /\* reset cam *\/ */
	    /* } */
	}
    }
  return (0);
}
