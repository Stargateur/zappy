/*
** connect_nbr.c for connect_nbr in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 04:36:06 2015 Antoine Plaskowski
*/

#include	"game.h"
#include	"player.h"
#include	"connect_nbr.h"
#include	"num_client.h"

bool		connect_nbr(t_game *game, t_player *player, char *arg)
{
  size_t	connect_nbr;

  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  connect_nbr = player_team_online(game->player, player->team->team);
  connect_nbr = player->team->connect_max - connect_nbr;
  if (write_num_client(player->client, connect_nbr) == true)
    return (true);
  return (false);
}
