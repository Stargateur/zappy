/*
** draw.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Mon Jun 22 14:37:29 2015 Alaric
** Last update Tue Jun 30 14:35:45 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"../include/server/map.h"
#include	"../include/server/node.h"

extern int	_shape_size;

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
  int		a = /*global*/5 * SIZE_X / 40;
  int		b = /*global*/5 * SIZE_X / 40;

  SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
  SDL_RenderDrawLine(renderer, a, b, a + _shape_size, b);
  SDL_RenderDrawLine(renderer, a, b, a, b + _shape_size);
  SDL_RenderDrawLine(renderer, a + _shape_size, b, a + _shape_size, b + _shape_size);
  SDL_RenderDrawLine(renderer, a, b + _shape_size, a + _shape_size, b + _shape_size);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
