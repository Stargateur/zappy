/*
** colorPixel.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Thu Jun 18 16:44:37 2015 Alaric
** Last update Fri Jun 19 17:31:52 2015 Alaric
*/

#include	<SDL/SDL_ttf.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	"include/color.h"

void            colorPixel(SDL_Surface *grid, RGBcolor col)
{
  Uint32        color;
  int           bpp;
  Uint8         *p;

  color = SDL_MapRGB(grid->format, col.r, col.g, col.b);
  SDL_LockSurface(grid);
  bpp = grid->format->BytesPerPixel;
  p = (Uint8 *)grid->pixels + col.y * grid->pitch + col.x * bpp;
  *(Uint32 *)p = color;
  SDL_UnlockSurface(grid);
}
