/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Sun Jul  5 19:58:22 2015 Antoine Plaskowski
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"int_handler.h"

void		key_move(SDL_Event event, t_map *map, t_display *display)
{
  if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
    {
      if (display->_horiz == 0)
	display->_horiz = map->width;
      display->_horiz -= 1;
    }
  if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
    {
      display->_horiz += 1;
      if (display->_horiz > map->width)
	display->_horiz = 0;
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
      if (display->_verti > map->height)
	display->_verti = 0;
    }
}

void		key_option(SDL_Event event, t_map *map, t_display *display)
{
  SDL_GetWindowSize(display->fenetre, &display->w, &display->h);
  if (event.key.keysym.scancode == SDL_SCANCODE_KP_PLUS)
    {
      if (display->_nb_case != 1)
	display->_nb_case--;
      display->_shape_size = (display->w - 150) / display->_nb_case - 1;
      display->_shape_size2 = display->h / display->_nb_case - 1;
    }
  if (event.key.keysym.scancode == SDL_SCANCODE_KP_MINUS)
    {
      if (display->_nb_case != map->height &&
	  display->_nb_case != map->width && display->_nb_case < 70)
	display->_nb_case++;
      display->_shape_size = (display->w - 150) / display->_nb_case - 1;
      display->_shape_size2 = display->h / display->_nb_case - 1;
    }
  if (event.key.keysym.scancode == SDL_SCANCODE_R)
    {
      display->_nb_case = 40;
      display->_shape_size = (display->w - 150) / display->_nb_case - 1;
      display->_shape_size2 = display->h / display->_nb_case - 1;
      display->_horiz = 0;
      display->_verti = 0;
    }
}

void		key_press(SDL_Event event, t_map *map, t_display *display)
{
  key_move(event, map, display);
  key_option(event, map, display);
  if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
    g_keep_running = false;
 }

int		input(t_display *display, t_map *map)
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  g_keep_running = false;
	  break;
	case SDL_MOUSEBUTTONDOWN:
	  display->_click_x = display->_horiz + (size_t)event.button.x
	    / (display->_shape_size + 1);
	  display->_click_y = display->_verti + (size_t)event.button.y
	    / (display->_shape_size2 + 1);
	  break;
	case SDL_KEYDOWN:
	  key_press(event, map, display);
	  break;
	}
    }
  return (0);
}
