/*
** player.c for player in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Tue Jun 30 17:27:25 2015 Antoine Plaskowski
** Last update Fri Jul  3 21:02:49 2015 Antoine Plaskowski
*/

#include	<string.h>
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

bool            add_action(t_player * const player, char * const str,
			   size_t const t)
{
  t_action      *action;

  if (player == NULL)
    return (true);
  if (len_node(&player->action->node) > 10)
    return (true);
  if ((action = parser(str, t)) == NULL)
    return (true);
  if (player->action == NULL)
    if (clock_gettime(CLOCK_MONOTONIC, &player->act) == -1)
      {
	perror("clock_gettime :");
	return (true);
      }
  player->action = put_node(&player->action->node, &action->node);
  if (player->action == NULL)
    return (true);
  return (false);
}

size_t		player_team_online(t_player *player, char *team)
{
  size_t	i;

  if (team == NULL)
    return (0);
  i = 0;
  player = first_node(&player->node);
  while (player != NULL)
    {
      if (player->client != NULL && player->team != NULL &&
	  strcmp(player->team, team) == 0)
	i++;
      player = player->node.next;
    }
  return (i);
}
