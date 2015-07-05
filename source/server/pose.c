/*
** pose.c for pose in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 02:22:10 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	"game.h"
#include	"player.h"
#include	"pose.h"
#include	"message.h"

bool		pose(t_game *game, t_player *player, char *arg)
{
  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  if (drop_item(&game->map, player, get_type_inv(strtok(arg, " "))) == true)
    return (true);
  add_string(player->client, OK);
  return (false);
}
