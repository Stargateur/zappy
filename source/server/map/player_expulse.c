/*
** player_expulse.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Jul  1 17:19:17 2015 zwertv_e
** Last update Sun Jul  5 17:02:36 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"map.h"
#include	"player.h"
#include	"expulse.h"

static t_expulse	true_exp(t_dir target, t_expulse exp)
{
  switch (target)
    {
    case NORTH:
      return (exp);
    case EAST:
      return (exp + 2 > E_EAST + 1 ? (exp + 2) % (E_EAST + 1) : exp + 2);
    case SOUTH:
      return (exp + 4 > E_EAST + 1 ? (exp + 4) % (E_EAST + 1) : exp + 4);
    case WEST:
      return (exp + 6 > E_EAST + 1 ? (exp + 6) % (E_EAST + 1) : exp + 6);
    }
  return (E_HERE);
}

t_expulse	expulse_player(t_map * const map,
			       t_player const * const player,
			       t_player * const target)
{
  switch (player->dir)
    {
    case NORTH:
      target->coord.y = next_y(map, target->coord.y);
      return (true_exp(target->dir, E_SOUTH));
    case SOUTH:
      target->coord.y = prev_y(map, target->coord.y);
      return (true_exp(target->dir, E_NORTH));
    case WEST:
      target->coord.x = prev_x(map, target->coord.x);
      return (true_exp(target->dir, E_EAST));
    case EAST:
      target->coord.x = next_x(map, target->coord.x);
      return (true_exp(target->dir, E_WEST));
    };
  return (E_HERE);
}
