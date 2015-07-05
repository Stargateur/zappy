/*
** draw.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Mon Jun 22 14:37:29 2015 Alaric
** Last update Sun Jul  5 22:48:54 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"map.h"
#include	"node.h"

void		draw_grid(t_map *map, t_display *d)
{
  size_t	a;

  (void)map;
  a = 0;
  while (a <= d->_nb_case * (d->_shape_size + 1))
    {
      SDL_RenderDrawLine(d->renderer, (int)a, 0, (int)a,
			 (int)(d->_nb_case * (d->_shape_size2 + 1)));
      a += d->_shape_size + 1;
    }
  a = 0;
  while (a <= d->_nb_case * (d->_shape_size2 + 1))
    {
      SDL_RenderDrawLine(d->renderer, 0, (int)a,
			 (int)(d->_nb_case * (d->_shape_size + 1)), (int)a);
      a += d->_shape_size2 + 1;
    }
}

void		select_pos(t_map *m, t_square *t, t_display *d,
			   SDL_Rect *DestR)
{
  if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
      && t->coord.y < d->_verti + d->_nb_case
      && t->coord.y >= d->_verti)
    {
      DestR->x = (int)((t->coord.x + (m->width - d->_horiz))
		      * (d->_shape_size + 1));
      DestR->y = (int)((t->coord.y - d->_verti)
		      * (d->_shape_size2 + 1));
    }
  else if (t->coord.y < (d->_nb_case + d->_verti) - m->height
	   && t->coord.x < d->_horiz + d->_nb_case && t->coord.x >= d->_horiz)
    {
      DestR->y = (int)((t->coord.y + (m->height - d->_verti))
		      * (d->_shape_size2 + 1));
      DestR->x = (int)((t->coord.x - d->_horiz)
		      * (d->_shape_size + 1));
    }
  else if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
	   && t->coord.y < (d->_nb_case + d->_verti) - m->height)
    {
      DestR->y = (int)((t->coord.y + (m->height - d->_verti))
		      * (d->_shape_size2 + 1));
      DestR->x = (int)((t->coord.x + (m->width - d->_horiz))
		      * (d->_shape_size + 1));
    }
}

void		draw_more_stone(t_map *map, t_texture *img, t_display *disp,
				SDL_Rect DestR)
{
  t_square	*tmp;

  tmp = first_node(&map->items->node);
  while (tmp != NULL)
    {
      select_pos(map, tmp, disp, &DestR);
      if (valid_aff_stone(map, tmp, disp) == 1)
	SDL_RenderCopy(disp->renderer, img->mine, NULL, &DestR);
      tmp = tmp->node.next;
    }
}

void		draw_stone(t_map *map, t_texture *img, t_display *disp)
{
  t_square	*tmp;
  SDL_Rect	DestR;

  tmp = first_node(&map->items->node);
  DestR.w = (int)disp->_shape_size;
  DestR.h = (int)disp->_shape_size2;
  while (tmp != NULL)
    {
      if (tmp->coord.x < disp->_horiz + disp->_nb_case
	   && tmp->coord.x >= disp->_horiz
	   && tmp->coord.y < disp->_verti + disp->_nb_case
	   && tmp->coord.y >= disp->_verti)
	{
	  DestR.x = (int)((tmp->coord.x - disp->_horiz)
			  * (disp->_shape_size + 1));
	  DestR.y = (int)((tmp->coord.y - disp->_verti)
			  * (disp->_shape_size2 + 1));
	  SDL_RenderCopy(disp->renderer, img->mine, NULL, &DestR);
	}
      tmp = tmp->node.next;
    }
  if (disp->_horiz + disp->_nb_case > map->width ||
      disp->_verti + disp->_nb_case > map->height)
    draw_more_stone(map, img, disp, DestR);
}

void		draw_select(t_display *disp, t_map *map, t_texture *img)
{
  size_t	a = (disp->_click_x - disp->_horiz) * (disp->_shape_size + 1);
  size_t	b = (disp->_click_y - disp->_verti) * (disp->_shape_size2 + 1);

  SDL_SetRenderDrawColor(disp->renderer, 0, 255, 255, 255);
  SDL_RenderDrawLine(disp->renderer, (int)a, (int)b,
		     (int)(a + disp->_shape_size + 1), (int)b);
  SDL_RenderDrawLine(disp->renderer, (int)a, (int)b,
		     (int)a, (int)(b + disp->_shape_size2 + 1));
  SDL_RenderDrawLine(disp->renderer, (int)(a + disp->_shape_size + 1),
		     (int)b, (int)(a + disp->_shape_size + 1),
		     (int)(b + disp->_shape_size2 + 1));
  SDL_RenderDrawLine(disp->renderer, (int)a, (int)(b + disp->_shape_size2 + 1),
		     (int)(a + disp->_shape_size + 1),
		     (int)(b + disp->_shape_size2 + 1));
  SDL_SetRenderDrawColor(disp->renderer, 255, 255, 255, 255);
  draw_inventory(map, img, disp);
}
