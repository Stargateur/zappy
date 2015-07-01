/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Wed Jul  1 17:44:28 2015 Kevin Costa
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"

int		input(t_display *display)
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  exit(1);
	case SDL_MOUSEBUTTONDOWN:
	  display->_click_x = event.button.x / (display->_shape_size + 1);
	  display->_click_y = event.button.y / (display->_shape_size + 1);
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
	    {
	      display->_horiz -= 1;
	      if (display->_horiz == -1)
		display->_horiz = 40;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
	    {
	      display->_horiz += 1;
	      if (display->_horiz > 40)
		display->_horiz = 0;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_UP)
	    {
	      display->_verti -= 1;
	      if (display->_verti == -1)
		display->_verti = 40;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
	    {
	      display->_verti += 1;
	      if (display->_verti > 40)
		display->_verti = 0;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
	    exit(1);
	  if (event.key.keysym.scancode == SDL_SCANCODE_KP_PLUS)
	    {
	      if (display->_nb_case != 1)
		display->_nb_case--;
	      display->_shape_size = SIZE_X / display->_nb_case;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_KP_MINUS)
	    {
	      if (display->_nb_case != 1)
		display->_nb_case++;
	      display->_shape_size = SIZE_X / display->_nb_case;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_R)
	    {
	      display->_shape_size = 24;
	      display->_nb_case = 40;
	      display->_horiz = 0;
	      display->_verti = 0;
	    }
	}
    }
  return (0);
}
