/*
** draw.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Mon Jun 22 14:37:29 2015 Alaric
** Last update Tue Jun 30 15:31:06 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"../include/server/map.h"
#include	"../include/server/node.h"

extern int	_shape_size;
extern int	_click_x;
extern int	_click_y;

void		draw_grid(SDL_Renderer *renderer, t_map *map)
{
  int           a;

  a = 0;
  while (a <= /*map->height * 25*/ SIZE_X)
    {
      SDL_RenderDrawLine(renderer, a, 0, a, /*map->width * 25*/SIZE_Y);
      a += _shape_size + 1;
    }
  a = 0;
  while (a <= /*map->width * 25*/ SIZE_Y)
    {
      SDL_RenderDrawLine(renderer, 0, a, /*map->height * 25*/ SIZE_X, a);
      a += _shape_size + 1;
    }
}

SDL_Renderer		*draw_stone(t_map *map, t_texture *img, SDL_Renderer *renderer)
{
  t_squarre	*tmp;
  SDL_Rect	DestR;

  tmp = first_node(&map->items->node);
  DestR.w = _shape_size;
  DestR.h = _shape_size;
  while (tmp != NULL)
    {
      if (tmp->x * (_shape_size + 1) < SIZE_X && tmp->y * (_shape_size + 1) < SIZE_Y)
	{
	  DestR.x = tmp->x * (_shape_size + 1);
	  DestR.y = tmp->y * (_shape_size + 1);
	  SDL_RenderCopy(renderer, img->mine, NULL, &DestR);
	}
      tmp = tmp->node.next;
    }
  return (renderer);
}

SDL_Renderer		*draw_select(SDL_Renderer *renderer)
{
  int		a = _click_x * (_shape_size + 1);
  int		b = _click_y * (_shape_size + 1);

  SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
  SDL_RenderDrawLine(renderer, a, b, a + _shape_size + 1, b);
  SDL_RenderDrawLine(renderer, a, b, a, b + _shape_size + 1);
  SDL_RenderDrawLine(renderer, a + _shape_size + 1, b, a + _shape_size + 1, b + _shape_size + 1);
  SDL_RenderDrawLine(renderer, a, b + _shape_size + 1, a + _shape_size + 1, b + _shape_size + 1);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
