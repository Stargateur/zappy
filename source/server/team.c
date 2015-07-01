/*
** team.c for team in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 05:33:47 2015 Antoine Plaskowski
** Last update Wed Jul  1 06:02:53 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<stddef.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"client.h"
#include	"game.h"
#include	"num_client.h"

static bool     set_client_player(t_client * const client, t_game * const game,
				  size_t const team)
{
  t_player      *player;
  size_t	connect_nbr;

  if (game->team[team].connect < game->team[team].connect_max)
    return (true);
  if ((player = find_free_player(game->player, game->team[team].team)) == NULL)
    player = init_player(&game->map, game->team[team].team, random(), random());
  if (player == NULL)
    return (true);
  game->team[team].connect++;
  game->player = put_node(&game->player->node, &player->node);
  client->player = player;
  player->client = client;
  connect_nbr = game->team[team].connect_max - game->team[team].connect;
  if (write_num_client(client, connect_nbr) == true)
    return (true);
  return (write_pos_player(client) == true);
}

bool		set_team(t_client * const client, t_game * const game,
			 char * str)
{
  size_t	team;

  str = strtok(str, " ");
  if (client == NULL || game == NULL || str == NULL || game->team == NULL)
    return (true);
  for (team = 0; team < game->size_team; team++)
    if (strncmp(game->team[team].team, str, game->team[team].len_team) == 0)
      return (set_client_player(client, game, team));
  return (true);
}
