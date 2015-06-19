/*
** init.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:37:38 2015 Alaric
** Last update Fri Jun 19 17:43:19 2015 Alaric
*/

//#include	<SDL/SDL_ttf.h>
#include	<SDL2/SDL.h>
//#include	<SDL/SDL_image.h>
#include	<unistd.h>
#include	"include/color.h"

SDL_Window	*init_video()
{
  //SDL_Surface	*ecran;
  SDL_Window	*fenetre;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      printf("SDL_Init Fail\n");
      exit(-1);
    }
  fenetre = SDL_CreateWindow("zappy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1001, 1001, SDL_WINDOW_RESIZABLE);
  //ecran = SDL_SetVideoMode(1001, 1001, 32, SDL_HWSURFACE);
  if (fenetre == NULL)
    {
      printf("CreateWindow Fail\n");
      exit(-1);
    }
  return (fenetre);
}

/*SDL_Surface	*init_grid()
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
  }*/
