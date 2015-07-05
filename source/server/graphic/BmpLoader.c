/*
** BmpLoader.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:08:40 2015 Alaric
** Last update Sun Jul  5 21:53:13 2015 Antoine Plaskowski
*/

#include	<SDL2/SDL.h>
#include	<SDL2/SDL_image.h>
#include	<unistd.h>
#include	"graphic.h"

SDL_Surface	*Bmp_Loader(char *path)
{
  SDL_Surface	*ret;

  ret = SDL_LoadBMP(path);
  if (ret == NULL)
    {
      printf("Fail load bmp : %s\n", path);
      exit(1);
    }
  return (ret);
}
