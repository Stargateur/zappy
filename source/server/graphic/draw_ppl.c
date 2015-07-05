/*
** draw_ppl.c for  in /home/degand/Projects/PSU_2014_zappy/source/server/graphic
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jul  3 14:48:57 2015 Alaric
** Last update Sun Jul  5 22:49:07 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"map.h"
#include	"game.h"
#include	"player.h"
#include	"node.h"

void		select_aff_ppl(t_display *d, t_texture *img, t_player *tmp,
			       SDL_Rect DestR)
{
  SDL_Rect	SrcR;

  SrcR.w = 24;
  SrcR.h = 24;
  SrcR.y = 0;
  if (tmp->dir == 0)
    SrcR.x = 72;
  else if (tmp->dir == 1)
    SrcR.x = 24;
  else if (tmp->dir == 2)
    SrcR.x = 0;
  else if (tmp->dir == 3)
    SrcR.x = 48;
  SDL_RenderCopy(d->renderer, img->cursor, &SrcR, &DestR);
}

void		select_pos_ppl(t_map *m, t_player *t, t_display *d,
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

void		draw_more_ppl(t_game *game, t_texture *img, t_display *disp,
			      SDL_Rect DestR)
{
  t_player	*tmp;

  tmp = first_node(&game->player->node);
  while (tmp != NULL)
    {
      select_pos_ppl(&game->map, tmp, disp, &DestR);
      if (valid_aff_ppl(&game->map, tmp, disp) == 1)
	select_aff_ppl(disp, img, tmp, DestR);
      tmp = tmp->node.next;
    }
}

void		draw_ppl(t_game *game, t_texture *img, t_display *disp)
{
  t_player	*tmp;
  SDL_Rect	DestR;

  tmp = first_node(&game->player->node);
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
	  select_aff_ppl(disp, img, tmp, DestR);
	}
      tmp = tmp->node.next;
    }
  if (disp->_horiz + disp->_nb_case > game->map.width ||
      disp->_verti + disp->_nb_case > game->map.height)
    draw_more_ppl(game, img, disp, DestR);
}
