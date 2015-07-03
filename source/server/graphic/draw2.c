/*
** draw2.c for draw2 in /home/costa_b/rendu/PSU_2014_zappy/source/server/graphic
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Fri Jul  3 13:54:53 2015 Kevin Costa
** Last update Fri Jul  3 17:27:37 2015 Kevin Costa
*/

#include	<SDL2/SDL.h>
#include <SDL/SDL_ttf.h>
#include	"graphic.h"
#include	"map.h"
#include	"node.h"

void		draw_inventory(t_map *map, t_texture *img, t_display *disp)
{
  SDL_Rect	DestR;
  SDL_Surface *background = NULL;
  SDL_Surface *message = NULL;
  SDL_Surface *screen = NULL;
  TTF_Font *font;
  SDL_Color textColor = { 255, 255, 255 };
  size_t	i;
  size_t	j;
  t_square	*tmp;

  if (TTF_Init() == -1)
    exit(0);
  SDL_WM_SetCaption("TTF", NULL);
  font = TTF_OpenFont("../../../TTF/police.ttf", 28);
  message = TTF_RenderText_Solid(font, "test", textColor);
  /* apply_surface(0, 0, NULL, disp->renderer); */
  apply_surface(0, 200, message, disp->renderer);
  tmp = first_node(&map->items->node);
  i = disp->_click_x;
  j = disp->_click_y;
  if (i > map->width)
    i -= map->width;
  if (j > map->width)
    j -= map->height;
  while (tmp != NULL)
    {
      if (tmp->coord.x == i && tmp->coord.y == j)
      	{
      	  printf("%lu %lu %lu %lu %lu %lu %lu\n", tmp->ressources.linemate, tmp->ressources.deraumere, tmp->ressources.sibur, tmp->ressources.mendiane, tmp->ressources.phiras, tmp->ressources.thystame, tmp->ressources.food);
      	  /* printf("linemate = %lu\n", tmp->ressources.linemate); */
      	  /* printf("deraumere = %lu\n", tmp->ressources.deraumere); */
      	  /* printf("sibur = %lu\n", tmp->ressources.sibur); */
      	  /* printf("mendiane = %lu\n", tmp->ressources.mendiane); */
      	  /* printf("phiras = %lu\n", tmp->ressources.phiras); */
      	  /* printf("thystame = %lu\n", tmp->ressources.thystame); */
      	  /* printf("food = %lu\n", tmp->ressources.food); */
      /* 	  /\* printf("x = %lu; y = %lu\n", tmp->coords.x, tmp->coords.y); *\/ */
      /* 	  /\* DestR.x = (int)((tmp->coords.x - disp->_horiz) *\/ */
      /* 	  /\* 		  * (disp->_shape_size + 1)); *\/ */
      /* 	  /\* DestR.y = (int)((tmp->coords.y - disp->_verti) *\/ */
      /* 	  /\* 		  * (disp->_shape_size + 1)); *\/ */
      /* 	  /\* FONT *\/ */
      	}
      tmp = tmp->node.next;
    }

  /* printf("i = %d\n", i); */
  /* printf("j = %d\n", j); */
  DestR.w = (int)disp->_shape_max;
  DestR.h = (int)disp->_shape_max;
  DestR.x = 1010;
  DestR.y = 20;
  SDL_RenderCopy(disp->renderer, img->linemate, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 70;
  SDL_RenderCopy(disp->renderer, img->deraumere, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 120;
  SDL_RenderCopy(disp->renderer, img->sibur, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 170;
  SDL_RenderCopy(disp->renderer, img->phiras, NULL, &DestR);
  DestR.x = 1010;
  DestR.y = 220;
  SDL_RenderCopy(disp->renderer, img->thystame, NULL, &DestR);
}
