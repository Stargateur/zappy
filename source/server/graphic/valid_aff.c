/*
** valid_aff.c for  in /home/degand/PSU_2014_zappy/source/server/graphic
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Sun Jul  5 22:19:22 2015 Alaric
** Last update Sun Jul  5 22:48:29 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	"graphic.h"
#include	"map.h"
#include	"game.h"
#include	"player.h"
#include	"node.h"

int		valid_aff_stone(t_map *m, t_square *t, t_display *d)
{
  if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
      && t->coord.y < d->_verti + d->_nb_case
      && t->coord.y >= d->_verti)
    return (1);
  else if (t->coord.y < (d->_nb_case + d->_verti) - m->height
	   && t->coord.x < d->_horiz + d->_nb_case && t->coord.x >= d->_horiz)
    return (1);
  else if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
	   && t->coord.y < (d->_nb_case + d->_verti) - m->height)
    return (1);
  return (0);
}

int		valid_aff_ppl(t_map *m, t_player *t, t_display *d)
{
  if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
      && t->coord.y < d->_verti + d->_nb_case
      && t->coord.y >= d->_verti)
    return (1);
  else if (t->coord.y < (d->_nb_case + d->_verti) - m->height
	   && t->coord.x < d->_horiz + d->_nb_case && t->coord.x >= d->_horiz)
    return (1);
  else if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
	   && t->coord.y < (d->_nb_case + d->_verti) - m->height)
    return (1);
  return (0);
}

int		valid_aff_egg(t_map *m, t_egg *t, t_display *d)
{
  if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
      && t->coord.y < d->_verti + d->_nb_case
      && t->coord.y >= d->_verti)
    return (1);
  else if (t->coord.y < (d->_nb_case + d->_verti) - m->height
	   && t->coord.x < d->_horiz + d->_nb_case && t->coord.x >= d->_horiz)
    return (1);
  else if (t->coord.x < (d->_nb_case + d->_horiz) - m->width
	   && t->coord.y < (d->_nb_case + d->_verti) - m->height)
    return (1);
  return (0);
}
