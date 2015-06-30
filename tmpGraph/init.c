/*
** init.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:37:38 2015 Alaric
** Last update Tue Jun 30 15:31:33 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	<unistd.h>
#include	"include/color.h"
#include	"graphic.h"

int		_shape_size = 24;
int		_click_x = 0;
int		_click_y = 0;
int		_nb_case = 40;

SDL_Window	*init_video()
{
  SDL_Window	*fenetre;

  fenetre = SDL_CreateWindow("zappy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_X + 151, SIZE_Y + 1, SDL_WINDOW_RESIZABLE);
  if (fenetre == NULL)
    {
      printf("%s\n", SDL_GetError());
      exit(-1);
    }
  return (fenetre);
}

SDL_Renderer	*init_renderer(SDL_Window *fenetre)
{
  SDL_Renderer	*renderer;

  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
    {
      printf("%s\n", SDL_GetError());
      exit(-1);
    }
  return (renderer);
}

void      	init_texture(t_texture *text, SDL_Renderer *renderer)
{
  text->loader = Bmp_Loader("BMP/Linemate.bmp");
  text->linemate = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
  text->loader = Bmp_Loader("BMP/Deraumere.bmp");
  text->deraumere = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
  text->loader = Bmp_Loader("BMP/Sibur.bmp");
  text->sibur = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
  text->loader = Bmp_Loader("BMP/Mendiane.bmp");
  text->mendiane = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
  text->loader = Bmp_Loader("BMP/Phiras.bmp");
  text->phiras = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
  text->loader = Bmp_Loader("BMP/Thystame.bmp");
  text->thystame = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
  text->loader = Bmp_Loader("BMP/Cursor.bmp");
  text->cursor = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
  text->loader = Bmp_Loader("BMP/Mine.bmp");
  text->mine = SDL_CreateTextureFromSurface(renderer, text->loader);
  SDL_FreeSurface(text->loader);
}
