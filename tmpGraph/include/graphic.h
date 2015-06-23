/*
** graphic.h for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph/include
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:52:55 2015 Alaric
** Last update Mon Jun 22 17:05:22 2015 Alaric
*/

#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

#include	<SDL2/SDL.h>
#include        "../../include/server/map.h"

#define		SIZE_X 1000
#define		SIZE_Y 1000
#define		SHAPE_SIZE 24

typedef	struct	s_texture
{
  SDL_Texture	*linemate;
  SDL_Texture	*deraumere;
  SDL_Texture	*sibur;
  SDL_Texture	*mendiane;
  SDL_Texture	*phiras;
  SDL_Texture	*thystame;
  SDL_Texture	*cursor;
}		t_texture;

void		draw_grid(SDL_Renderer *);
SDL_Surface	*Bmp_Loader(char *);
SDL_Window	*init_video();
SDL_Renderer	*init_renderer(SDL_Window *);
void		init_texture(t_texture *, SDL_Renderer *);
SDL_Renderer	*draw_stone(t_map *, t_texture *, SDL_Renderer *);

#endif		/* !GRAPHIC_H_ */
