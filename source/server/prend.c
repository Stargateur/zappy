/*
** prend.c for prend in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 02:02:07 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	"game.h"
#include	"player.h"
#include	"prend.h"
#include	"message.h"

bool		prend(t_game *game, t_player *player, char *arg)
{
  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  if (take_item(&game->map, player, get_type_inv(strtok(arg, " "))) == true)
    return (true);
  add_string(player->client, OK);
  return (false);
}
