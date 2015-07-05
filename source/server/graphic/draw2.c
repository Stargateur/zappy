/*
** draw2.c for draw2 in /home/costa_b/rendu/PSU_2014_zappy/source/server/graphic
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Fri Jul  3 13:54:53 2015 Kevin Costa
** Last update Sun Jul  5 19:51:19 2015 Kevin Costa
*/

#include	<SDL2/SDL.h>
#include	<SDL2/SDL_ttf.h>
#include	"graphic.h"
#include	"map.h"
#include	"node.h"

void		draw_inventory(t_map *map, t_texture *img, t_display *disp)
{
  SDL_Rect	DestR;
  size_t	i;
  size_t	j;
  t_square	*tmp;

  DestR.w = 100;
  DestR.h = 100;
  DestR.x = (int)((disp->_shape_size + 1) * disp->_nb_case + 15);
  img->loader = NULL;
  tmp = first_node(&map->items->node);
  i = disp->_click_x;
  j = disp->_click_y;
  if (i >= map->width)
    i -= map->width;
  if (j >= map->height)
    j -= map->height;
  while (tmp != NULL)
    {
      if (tmp->coord.x == i && tmp->coord.y == j)
	draw_items(img, disp, tmp, DestR);
      tmp = tmp->node.next;
    }
}

void		draw_items(t_texture *img, t_display *disp,
			   t_square *tmp, SDL_Rect DestR)
{
  SDL_Texture	*ecr;
  SDL_Color	textColor = {250, 250, 250, 0};

  sprintf(img->text, "Linemate : %lu", tmp->ressources.linemate);
  img->loader = TTF_RenderText_Solid(disp->font, img->text, textColor);
  ecr = SDL_CreateTextureFromSurface(disp->renderer, img->loader);
  SDL_FreeSurface(img->loader);
  DestR.y = 20;
  SDL_SetRenderDrawColor(disp->renderer, 250, 250, 250, 250);
  SDL_RenderCopy(disp->renderer, ecr, NULL, &DestR);
  sprintf(img->text, "Deraumere : %lu", tmp->ressources.deraumere);
  img->loader = TTF_RenderText_Solid(disp->font, img->text, textColor);
  ecr = SDL_CreateTextureFromSurface(disp->renderer, img->loader);
  SDL_FreeSurface(img->loader);
  DestR.y = 120;
  SDL_SetRenderDrawColor(disp->renderer, 250, 250, 250, 250);
  SDL_RenderCopy(disp->renderer, ecr, NULL, &DestR);
  sprintf(img->text, "Sibur : %lu", tmp->ressources.sibur);
  img->loader = TTF_RenderText_Solid(disp->font, img->text, textColor);
  ecr = SDL_CreateTextureFromSurface(disp->renderer, img->loader);
  SDL_FreeSurface(img->loader);
  DestR.y = 220;
  SDL_SetRenderDrawColor(disp->renderer, 250, 250, 250, 250);
  SDL_RenderCopy(disp->renderer, ecr, NULL, &DestR);
  draw_items_next(img, disp, tmp, DestR);
}

void		draw_items_next(t_texture *img, t_display *disp,
				t_square *tmp, SDL_Rect DestR)
{
  SDL_Texture	*ecr;
  SDL_Color	textColor = {250, 250, 250, 0};

  sprintf(img->text, "Phiras : %lu", tmp->ressources.phiras);
  img->loader = TTF_RenderText_Solid(disp->font, img->text, textColor);
  ecr = SDL_CreateTextureFromSurface(disp->renderer, img->loader);
  SDL_FreeSurface(img->loader);
  DestR.y = 320;
  SDL_SetRenderDrawColor(disp->renderer, 250, 250, 250, 250);
  SDL_RenderCopy(disp->renderer, ecr, NULL, &DestR);
  sprintf(img->text, "Thystame : %lu", tmp->ressources.thystame);
  img->loader = TTF_RenderText_Solid(disp->font, img->text, textColor);
  ecr = SDL_CreateTextureFromSurface(disp->renderer, img->loader);
  SDL_FreeSurface(img->loader);
  DestR.y = 420;
  SDL_SetRenderDrawColor(disp->renderer, 250, 250, 250, 250);
  SDL_RenderCopy(disp->renderer, ecr, NULL, &DestR);
  sprintf(img->text, "Food : %lu", tmp->ressources.food);
  img->loader = TTF_RenderText_Solid(disp->font, img->text, textColor);
  ecr = SDL_CreateTextureFromSurface(disp->renderer, img->loader);
  SDL_FreeSurface(img->loader);
  DestR.y = 520;
  SDL_SetRenderDrawColor(disp->renderer, 250, 250, 250, 250);
  SDL_RenderCopy(disp->renderer, ecr, NULL, &DestR);
  draw_bonus(img, disp, DestR);
}

void		draw_bonus(t_texture *img, t_display *disp, SDL_Rect DestR)
{
  DestR.w = (int)disp->_shape_max;
  DestR.h = (int)disp->_shape_max;
  DestR.y = 15;
  SDL_RenderCopy(disp->renderer, img->linemate, NULL, &DestR);
  DestR.y = 115;
  SDL_RenderCopy(disp->renderer, img->deraumere, NULL, &DestR);
  DestR.y = 215;
  SDL_RenderCopy(disp->renderer, img->sibur, NULL, &DestR);
  DestR.y = 315;
  SDL_RenderCopy(disp->renderer, img->phiras, NULL, &DestR);
  DestR.y = 415;
  SDL_RenderCopy(disp->renderer, img->thystame, NULL, &DestR);
  DestR.y = 515;
  SDL_RenderCopy(disp->renderer, img->food, NULL, &DestR);
}
