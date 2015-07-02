/*
** BmpLoader.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:08:40 2015 Alaric
** Last update Fri Jun 19 15:20:02 2015 Alaric
*/

#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	<unistd.h>

SDL_Surface	*Bmp_Loader(char *path)
{
  SDL_Surface	*ret;

  ret = SDL_LoadBMP(path);
  if (ret == NULL)
    {
      printf("Fail load bmp : %s\n", path);
      exit(0);
    }
  return (ret);
}
