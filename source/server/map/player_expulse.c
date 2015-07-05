/*
** player_expulse.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Jul  1 17:19:17 2015 zwertv_e
** Last update Sun Jul  5 02:25:24 2015 Antoine Plaskowski
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
      target->coord.y = prev_y(map, target->coord.y);
      break;
    case SOUTH:
      target->coord.y = next_y(map, target->coord.y);
      break;
    case WEST:
      target->coord.x = prev_x(map, target->coord.x);
      break;
    case EAST:
      target->coord.x = next_x(map, target->coord.x);
      break;
    };
}

bool		expulse_players(t_game * const game,
				t_map * const map,
				t_player const * const player)
{
  t_player	*tmp;
  bool		ret;

  if (map == NULL || player == NULL)
    return (true);
  ret = true;
  tmp = first_node(&game->player->node);
  while (tmp != NULL)
    {
      if (tmp != player && tmp->coord.x == player->coord.x &&
	  tmp->coord.y == player->coord.y)
	{
	  ret = false;
	  expulse_player(map, player, tmp);
	}
      tmp = tmp->node.next;
    }
  return (ret);
}
