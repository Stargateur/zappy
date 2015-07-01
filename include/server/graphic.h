/*
** graphic.h for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph/include
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:52:55 2015 Alaric
** Last update Wed Jul  1 13:47:02 2015 Kevin Costa
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
  SDL_Texture	*mine;
  SDL_Surface	*loader;
}		t_texture;

typedef struct s_display
{
  int		_shape_size;
  int		_click_x;
  int		_click_y;
  int		_nb_case;
  int		_verti;
  int		_horiz;
  SDL_Renderer	*renderer;
}		t_display;

void		draw_grid(t_map *, t_display *);
SDL_Surface	*Bmp_Loader(char *);
SDL_Window	*init_video();
t_display	*init_renderer(SDL_Window *, t_display *);
void		init_texture(t_texture *, SDL_Renderer *);
SDL_Renderer	*draw_stone(t_map *, t_texture *, t_display *);
void		draw_select(t_display *);
int		input(t_display *);

#endif		/* !GRAPHIC_H_ */
