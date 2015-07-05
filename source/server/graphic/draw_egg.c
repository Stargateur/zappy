/*
** draw_egg.c for draw_egg in /home/costa_b/rendu/PSU_2014_zappy/source/server/graphic
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sat Jul  4 19:58:41 2015 Kevin Costa
** Last update Sun Jul  5 22:49:24 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"map.h"
#include	"egg.h"
#include	"game.h"
#include	"node.h"

void		select_pos_egg(t_map *m, t_egg *t, t_display *d,
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

void		draw_more_egg(t_game *game, t_texture *img, t_display *disp,
			      SDL_Rect DestR)
{
  t_egg		*tmp;

  tmp = first_node(&game->egg->node);
  while (tmp != NULL)
    {
      select_pos_egg(&game->map, tmp, disp, &DestR);
      if (valid_aff_egg(&game->map, tmp, disp) == 1)
	SDL_RenderCopy(disp->renderer, img->egg, NULL, &DestR);
      tmp = tmp->node.next;
    }
}

void		draw_egg(t_game *game, t_texture *img, t_display *disp)
{
  t_egg		*tmp;
  SDL_Rect	DestR;

  tmp = first_node(&game->egg->node);
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
	  SDL_RenderCopy(disp->renderer, img->egg, NULL, &DestR);
	}
      tmp = tmp->node.next;
    }
  if (disp->_horiz + disp->_nb_case > game->map.width ||
      disp->_verti + disp->_nb_case > game->map.height)
    draw_more_egg(game, img, disp, DestR);
}
