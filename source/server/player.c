/*
** player.c for player in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Jun 30 17:27:25 2015 Antoine Plaskowski
** Last update Tue Jun 30 17:45:31 2015 Antoine Plaskowski
*/

#include	"player.h"

t_player	*find_free_player(t_player *player, char * const team)
{
  if (team == NULL)
    return (NULL);
  player = first_node(&player->node);
  while (player != NULL)
    {
      if (player->client == NULL && player->team != NULL &&
	  strcmp(player->team, team) == 0)
	return (player);
      player = player->node.next;
    }
  return (NULL);
}
