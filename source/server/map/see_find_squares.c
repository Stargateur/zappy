/*
** see_find_squares.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Jul  3 20:39:08 2015 zwertv_e
** Last update Sun Jul  5 00:12:37 2015 Antoine Plaskowski
*/

#include	<stdint.h>
#include	"map.h"
#include	"player.h"

size_t		find_nb_squares(size_t const accu, size_t const range)
{
  if (range == 0)
    return (accu);
  return (find_nb_squares(accu + 1 + 2 * range, range - 1));
}

void		find_squares(t_map const * const map,
			     t_player const * const player, t_coord *list,
			     size_t const range)
{
  size_t	i;
  intmax_t	tmp_h;
  intmax_t	tmp_w;

  i = 0;
  tmp_h = 0;
  while (tmp_h <= (intmax_t)player->range)
    {
      tmp_w = -((2 * tmp_h + 1) / 2);
      while (tmp_w <= (2 * tmp_h + 1) / 2)
	{
	  if (i < range)
	    {
	      list[i].x = get_x(map, player, tmp_h, tmp_w);
	      list[i].y = get_y(map, player, tmp_h, tmp_w);
	    }
	  tmp_w++;
	  i++;
	}
      tmp_h++;
    }
}
