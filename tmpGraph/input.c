/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Tue Jun 30 15:51:34 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"

extern int	_shape_size;
extern int	_click_x;
extern int	_click_y;
extern int	_nb_case;

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
	  _click_x = event.button.x / (_shape_size + 1);
	  _click_y = event.button.y / (_shape_size + 1);
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
	  if (event.key.keysym.scancode == SDL_SCANCODE_KP_PLUS)
	    {
	      if (_nb_case != 1)
		_nb_case--;
	      _shape_size = SIZE_X / _nb_case;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_KP_MINUS)
	    {
	      if (_nb_case != 1)
		_nb_case++;
	      _shape_size = SIZE_X / _nb_case;
	    }
	  /*case SDL_SCANCODE_KP_PLUS: */
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
