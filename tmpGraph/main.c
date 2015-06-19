/*
** main.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Thu Jun 18 15:58:26 2015 Alaric
** Last update Fri Jun 19 15:24:48 2015 Alaric
*/

#include	<SDL/SDL_ttf.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<unistd.h>
#include	"color.h"

SDL_Surface	*init_grid()
{
  SDL_Surface	*grid;
  RGBcolor	white;

  grid = SDL_CreateRGBSurface(SDL_HWSURFACE, 1001, 1001, 32, 0, 0, 0, 0);
  white.r = 255;
  white.g = 255;
  white.b = 255;
  white.x = 0;
  while (white.x <= 1000)
    {
      white.y = 0;
      while (++white.y < 1000)
        colorPixel(grid, white);
      white.x += 1000 / 40;
    }
  white.y = 0;
  while (white.y <= 1000)
    {
      white.x = 0;
      while (++white.x < 1000)
        colorPixel(grid, white);
      white.y += 1000 / 40;
    }
  return (grid);
}

int		main()
{
  SDL_Surface	*ecran;
  SDL_Surface	*grid;
  SDL_Surface	*linemate;
  SDL_Rect	pos;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      printf("Init Fail\n");
      return (-1);
    }
  ecran = SDL_SetVideoMode(1001, 1001, 32, SDL_HWSURFACE);
  if (ecran == NULL)
    {
      printf("Set Fail\n");
      return (-1);
    }
  linemate = Bmp_Loader("BMP/Linemate.bmp");
  SDL_WM_SetCaption("zappy", NULL);
  grid = init_grid();
  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(grid, NULL, ecran, &pos);
  pos.x = 1;
  pos.y = 1;
  SDL_BlitSurface(linemate, NULL, ecran, &pos);
  SDL_Flip(ecran);
  sleep(5);
  SDL_Quit();
  return (0);
}
