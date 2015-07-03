/*
** graphic.h for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph/include
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:52:55 2015 Alaric
** Last update Fri Jul  3 14:16:02 2015 Kevin Costa
*/

#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

#include	<SDL2/SDL.h>
#include        "map.h"

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
  size_t	_shape_size;
  size_t	_shape_max;
  size_t	_click_x;
  size_t	_click_y;
  size_t	_nb_case;
  size_t	_verti;
  size_t	_horiz;
  SDL_Renderer	*renderer;
}		t_display;

void		draw_grid(t_map *, t_display *);
SDL_Surface	*Bmp_Loader(char *);
SDL_Window	*init_video();
t_display	*init_renderer(SDL_Window *, t_display *);
void		init_texture(t_texture *, SDL_Renderer *);
void		draw_stone(t_map *, t_texture *, t_display *);
void		draw_more_stone(t_map *, t_texture *, t_display *, SDL_Rect);
void		draw_select(t_display *, t_map *, t_texture *);
void		key_move(SDL_Event, t_map *, t_display *);
void		key_option(SDL_Event, t_map *, t_display *);
void		key_press(SDL_Event, t_map *, t_display *);
int		input(t_display *, t_map *);
void            select_pos(t_map *, t_square *, t_display *, SDL_Rect *);
void            draw_inventory(t_map *, t_texture *, t_display *);

#endif		/* !GRAPHIC_H_ */
