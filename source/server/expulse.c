/*
** expulse.c for expulse in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 17:06:16 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"game.h"
#include	"player.h"
#include	"expulse.h"
#include	"message.h"

static bool	aux_expulse(t_game *game, t_map *map, t_player *player)
{
  t_player	*tmp;
  char		*str;
  bool		ret;
  t_expulse	exp;

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
	  exp = expulse_player(map, player, tmp);
	  str = malloc_vsnprintf("deplacement : %d\n", exp);
	  add_string(tmp->client, str);
	  free(str);
	}
      tmp = tmp->node.next;
    }
  return (ret);
}

bool		expulse(t_game *game, t_player *player, char *arg)
{
  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  if (aux_expulse(game, &game->map, player) == true)
    return (true);
  add_string(player->client, OK);
  return (false);
}
