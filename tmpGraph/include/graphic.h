/*
** graphic.h for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph/include
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jun 19 15:52:55 2015 Alaric
** Last update Mon Jun 22 09:55:35 2015 Alaric
*/

#ifndef		GRAPHIC_H_
# define	GRAPHIC_H_

#include	<SDL2/SDL.h>

#define		SIZE_X 1000
#define		SIZE_Y 1000
#define		SHAPE_SIZE 24

void		draw_grid(SDL_Renderer *);
SDL_Surface	*Bmp_Loader(char *);
SDL_Window	*init_video();
SDL_Renderer	*init_renderer(SDL_Window *);

#endif		/* !GRAPHIC_H_ */
