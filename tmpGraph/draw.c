/*
** draw.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Mon Jun 22 14:37:29 2015 Alaric
** Last update Mon Jun 22 17:17:29 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"include/graphic.h"
#include	"../include/server/map.h"

void		draw_grid(SDL_Renderer *renderer)
{
  int           a;

  a = 0;
  while (a <= 1000)
    {
      SDL_RenderDrawLine(renderer, a, 0, a, 1000);
      a += SIZE_X / 40;
    }
  a = 0;
  while (a <= 1000)
    {
      SDL_RenderDrawLine(renderer, 0, a, 1000, a);
      a += SIZE_Y / 40;
    }
}

SDL_Renderer		*draw_stone(t_map *map, t_texture *img, SDL_Renderer *renderer)
{
  t_squarre	*tmp;
  SDL_Rect	DestR;

  tmp = map->items;
  DestR.w = SHAPE_SIZE;
  DestR.h = SHAPE_SIZE;
  //while (tmp != NULL)
  // {
  DestR.x = map->items->x * (SIZE_X / 40) + 1;
  DestR.y = map->items->y * (SIZE_Y / 40) + 1;
  SDL_RenderCopy(renderer, img->phiras, NULL, &DestR);
  //tmp = tmp->next;
  //  }
  return (renderer);
}
