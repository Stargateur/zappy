/*
** player_expulse.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Jul  1 17:19:17 2015 zwertv_e
** Last update Fri Jul  3 14:50:38 2015 zwertv_e
*/

#include	"map.h"
#include	"player.h"

static void	expulse_player(t_map * const map,
			       t_player const * const player,
			       t_player * const target)
{
  switch (player->dir)
    {
    case NORTH:
      target->coords.y = prev_y(map, target->coords.y);
      break;
    case SOUTH:
      target->coords.y = next_y(map, target->coords.y);
      break;
    case WEST:
      target->coords.x = prev_x(map, target->coords.x);
      break;
    case EAST:
      target->coords.x = next_x(map, target->coords.x);
      break;
    };
}

bool		expulse_players(t_game * const game,
				t_map * const map,
				t_player const * const player)
{
  t_player	*tmp;

  if (!map || !player)
    return (false);
  tmp = first_node(&game->player->node);
  while (tmp)
    {
      if (tmp != player && tmp->coords.x == player->coords.x &&
	  tmp->coords.y == player->coords.y)
	expulse_player(map, player, tmp);
      tmp = tmp->node.next;
    }
  return (true);
}
