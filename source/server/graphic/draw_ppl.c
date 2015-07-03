/*
** draw_ppl.c for  in /home/degand/Projects/PSU_2014_zappy/source/server/graphic
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Fri Jul  3 14:48:57 2015 Alaric
** Last update Fri Jul  3 16:15:54 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"map.h"
#include	"node.h"

void		select_aff_ppl(t_display *d, t_texture *img, t_player *tmp,
			       SDL_Rect DestR)
{
  SDL_Rect	SrcR;

  SrcR.w = 24;
  SrcR.h = 24;
  SrcR.y = 0;
  if (tmp->dir == 0)
    SrcR.x = 24;
  else if (tmp->dir == 1)
    SrcR.x = 72;
  else if (tmp->dir == 2)
    SrcR.x = 0;
  else if (tmp->dir == 3)
    SrcR.x = 48;
  SDL_RenderCopy(d->renderer, img->cursor, &SrcR, &DestR);
}

void		draw_more_ppl(t_game *game, t_texture *img, t_display *disp,
				SDL_Rect DestR)
{
  t_player	*tmp;

  tmp = first_node(game->player->node);
  while (tmp != NULL)
    {
      select_pos(game->map, tmp, disp, &DestR);
      select_aff_ppl(disp, img, tmp, DestR);
      tmp = tmp->node.next;
    }
}

void		draw_ppl(t_game *game, t_texture *img, t_display *disp)
{
  t_player	*tmp;
  SDL_Rect	DestR;

  tmp = first_node(game->player->node);
  DestR.w = (int)disp->_shape_size;
  DestR.h = (int)disp->_shape_size;
  while (tmp != NULL)
    {
      if (tmp->coords.x < disp->_horiz + disp->_nb_case
	   && tmp->coords.x >= disp->_horiz
	   && tmp->coords.y < disp->_verti + disp->_nb_case
	   && tmp->coords.y >= disp->_verti)
	{
	  DestR.x = (int)((tmp->coords.x - disp->_horiz)
			  * (disp->_shape_size + 1));
	  DestR.y = (int)((tmp->coords.y - disp->_verti)
			  * (disp->_shape_size + 1));
	  select_aff_ppl(disp, img, tmp, DestR);
	}
      tmp = tmp->node.next;
    }
  if (disp->_horiz + disp->_nb_case > game->map->width ||
      disp->_verti + disp->_nb_case > game->map->height)
    draw_more_ppl(game, img, disp, DestR);
}
