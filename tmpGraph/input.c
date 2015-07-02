/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Thu Jul  2 18:12:51 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"

int		input(t_display *display, t_map *map)
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  exit(1);
	case SDL_MOUSEBUTTONDOWN:
	  display->_click_x = display->_horiz + event.button.x / (display->_shape_size + 1);
	  display->_click_y = display->_verti + event.button.y / (display->_shape_size + 1);
	case SDL_KEYDOWN:
	  if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
	    {
	      if (display->_horiz == 0)
		display->_horiz = map->width;
	      display->_horiz -= 1;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
	    {
	      display->_horiz += 1;
	      /* display->_grid_x -= 1; */
	      /* display->_grid_y -= 1; */
	      if (display->_horiz > map->width)
		{
		  /* display->_grid_x = 50; */
		  /* display->_grid_y = 40; */
		  display->_horiz = 0;
		}
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_UP)
	    {
	      if (display->_verti == 0)
		display->_verti = map->height;
	      display->_verti -= 1;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
	    {
	      display->_verti += 1;
	      /* display->_grid_y -= 1; */
	      if (display->_verti > map->height)
		{
		  /* display->_grid_y = 50; */
		  display->_verti = 0;
		}
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
	    exit(1);
	  if (event.key.keysym.scancode == SDL_SCANCODE_KP_PLUS)
	    {
	      if (display->_nb_case != 1)
		display->_nb_case--;
	      display->_shape_size = SIZE_X / display->_nb_case - 1;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_KP_MINUS)
	    {
	      if (display->_nb_case != map->height && display->_nb_case != map->width)
		display->_nb_case++;
	      display->_shape_size = SIZE_X / display->_nb_case - 1;
	    }
	  if (event.key.keysym.scancode == SDL_SCANCODE_R)
	    {
	      display->_shape_size = 24;
	      display->_nb_case = 40;
	      display->_horiz = 0;
	      display->_verti = 0;
	      /* display->_grid_x = 50; */
	      /* display->_grid_y = 50; */
	    }
	}
    }
  return (0);
}
