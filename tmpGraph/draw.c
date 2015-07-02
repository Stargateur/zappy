/*
** draw.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Mon Jun 22 14:37:29 2015 Alaric
** Last update Thu Jul  2 17:31:37 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"map.h"
#include	"node.h"

void		draw_grid(t_map *map, t_display *d)
{
  int           a;

  (void)map;
  a = 0;
  while (a <= d->_nb_case * (d->_shape_size + 1))
    {
      SDL_RenderDrawLine(d->renderer, a, 0, a, d->_nb_case * (d->_shape_size + 1));
      a += d->_shape_size + 1;
    }
  a = 0;
  while (a <= d->_nb_case * (d->_shape_size + 1))
    {
      SDL_RenderDrawLine(d->renderer, 0, a, d->_nb_case * (d->_shape_size + 1), a);
      a += d->_shape_size + 1;
    }
}

void		draw_more_stone(t_map *map, t_texture *img, t_display *disp, SDL_Rect DestR)
{
  t_square	*tmp;

  tmp = first_node(&map->items->node);
  while (tmp != NULL)
    {
      if (tmp->coords.x < (disp->_nb_case + disp->_horiz) - map->width
	   && tmp->coords.y < disp->_verti + disp->_nb_case
	   && tmp->coords.y >= disp->_verti)
	{
	  DestR.x = (tmp->coords.x + (map->width - disp->_horiz)) * (disp->_shape_size + 1);
	  DestR.y = (tmp->coords.y - disp->_verti) * (disp->_shape_size + 1);
	}
      else if (tmp->coords.y < (disp->_nb_case + disp->_verti) - map->height
	   && tmp->coords.x < disp->_horiz + disp->_nb_case
	   && tmp->coords.x >= disp->_horiz)
	{
	  DestR.y = (tmp->coords.y + (map->height - disp->_verti)) * (disp->_shape_size + 1);
	  DestR.x = (tmp->coords.x - disp->_horiz) * (disp->_shape_size + 1);
	}
      else if (tmp->coords.x < (disp->_nb_case + disp->_horiz) - map->width
	       && tmp->coords.y < (disp->_nb_case + disp->_verti) - map->height)
	{
	  DestR.y = (tmp->coords.y + (map->height - disp->_verti)) * (disp->_shape_size + 1);
	  DestR.x = (tmp->coords.x + (map->width - disp->_horiz)) * (disp->_shape_size + 1);
	}
      SDL_RenderCopy(disp->renderer, img->mine, NULL, &DestR);
      tmp = tmp->node.next;
    }
}

void		draw_stone(t_map *map, t_texture *img, t_display *disp)
{
  t_square	*tmp;
  SDL_Rect	DestR;

  tmp = first_node(&map->items->node);
  DestR.w = disp->_shape_size;
  DestR.h = disp->_shape_size;
  while (tmp != NULL)
    {
      if (tmp->coords.x < disp->_horiz + disp->_nb_case
	   && tmp->coords.x >= disp->_horiz
	   && tmp->coords.y < disp->_verti + disp->_nb_case
	   && tmp->coords.y >= disp->_verti)
	{
	  DestR.x = (tmp->coords.x - disp->_horiz) * (disp->_shape_size + 1);
	  DestR.y = (tmp->coords.y - disp->_verti) * (disp->_shape_size + 1);
	  SDL_RenderCopy(disp->renderer, img->mine, NULL, &DestR);
	}
      tmp = tmp->node.next;
    }
  if (disp->_horiz + disp->_nb_case > map->width || disp->_verti + disp->_nb_case > map->height)
    draw_more_stone(map, img, disp, DestR);
}

void		draw_select(t_display *display)
{
  int		a = display->_click_x * (display->_shape_size + 1);
  int		b = display->_click_y * (display->_shape_size + 1);

  SDL_SetRenderDrawColor(display->renderer, 0, 255, 255, 255);
  SDL_RenderDrawLine(display->renderer, a, b, a + display->_shape_size + 1, b);
  SDL_RenderDrawLine(display->renderer, a, b, a, b + display->_shape_size + 1);
  SDL_RenderDrawLine(display->renderer, a + display->_shape_size + 1, b, a + display->_shape_size + 1, b + display->_shape_size + 1);
  SDL_RenderDrawLine(display->renderer, a, b + display->_shape_size + 1, a + display->_shape_size + 1, b + display->_shape_size + 1);
  SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255);
}
