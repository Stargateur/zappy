/*
** draw.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Mon Jun 22 14:37:29 2015 Alaric
** Last update Thu Jun 25 17:11:06 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"../include/server/map.h"
#include	"../include/server/node.h"

void		draw_grid(SDL_Renderer *renderer, t_map *map)
{
  int           a;

  a = 0;
  while (a <= map->height * 25)
    {
      SDL_RenderDrawLine(renderer, a, 0, a, map->width * 25);
      a += SIZE_X / 40;
    }
  a = 0;
  while (a <= map->width * 25)
    {
      SDL_RenderDrawLine(renderer, 0, a, map->height * 25, a);
      a += SIZE_Y / 40;
    }
}

SDL_Renderer		*draw_stone(t_map *map, t_texture *img, SDL_Renderer *renderer)
{
  t_squarre	*tmp;
  SDL_Rect	DestR;

  tmp = first_node(&map->items->node);
  DestR.w = SHAPE_SIZE;
  DestR.h = SHAPE_SIZE;
  while (tmp != NULL)
    {
      DestR.x = tmp->x * (SIZE_X / 40) + 1;
      DestR.y = tmp->y * (SIZE_Y / 40) + 1;
      SDL_RenderCopy(renderer, img->mine, NULL, &DestR);
      tmp = tmp->node.next;
    }
  return (renderer);
}
