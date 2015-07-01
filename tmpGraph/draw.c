/*
** draw.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Mon Jun 22 14:37:29 2015 Alaric
** Last update Wed Jul  1 13:47:57 2015 zwertv_e
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"../include/server/map.h"
#include	"../include/server/node.h"

void		draw_grid(t_map *map, t_display *display)
{
  int           a;

  (void)map;
  a = 0;
  while (a <= /*map->height * 25*/ SIZE_X)
    {
      SDL_RenderDrawLine(display->renderer, a, 0, a, /*map->width * 25*/SIZE_Y);
      a += display->_shape_size + 1;
    }
  a = 0;
  while (a <= /*map->width * 25*/ SIZE_Y)
    {
      SDL_RenderDrawLine(display->renderer, 0, a, /*map->height * 25*/ SIZE_X, a);
      a += display->_shape_size + 1;
    }
}

SDL_Renderer		*draw_stone(t_map *map, t_texture *img, t_display *display)
{
  t_square	*tmp;
  SDL_Rect	DestR;

  tmp = first_node(&map->items->node);
  DestR.w = display->_shape_size;
  DestR.h = display->_shape_size;
  while (tmp != NULL)
    {
      if (tmp->coords.x * (display->_shape_size + 1) < SIZE_X && tmp->coords.y * (display->_shape_size + 1) < SIZE_Y)
	{
	  DestR.x = tmp->coords.x * (display->_shape_size + 1);
	  DestR.y = tmp->coords.y * (display->_shape_size + 1);
	  SDL_RenderCopy(display->renderer, img->mine, NULL, &DestR);
	}
      tmp = tmp->node.next;
    }
  return (display->renderer);
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
