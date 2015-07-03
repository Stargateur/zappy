/*
** draw2.c for draw2 in /home/costa_b/rendu/PSU_2014_zappy/source/server/graphic
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Fri Jul  3 13:54:53 2015 Kevin Costa
** Last update Fri Jul  3 14:16:13 2015 Kevin Costa
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"map.h"
#include	"node.h"

void		draw_inventory(t_map *map, t_texture *img, t_display *disp)
{
  SDL_Rect	DestR;

  DestR.w = (int)disp->_shape_max;
  DestR.h = (int)disp->_shape_max;
  DestR.x = 1010;
  DestR.y = 20;
  SDL_RenderCopy(disp->renderer, img->linemate, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 70;
  SDL_RenderCopy(disp->renderer, img->deraumere, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 120;
  SDL_RenderCopy(disp->renderer, img->sibur, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 170;
  SDL_RenderCopy(disp->renderer, img->phiras, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 220;
  SDL_RenderCopy(disp->renderer, img->thystame, NULL, &DestR);
}
