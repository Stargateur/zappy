/*
** inventaire.c for inventaire in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 03:53:32 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"game.h"
#include	"player.h"
#include	"inventaire.h"

bool		inventaire(t_game *game, t_player *player, char *arg)
{
  char		*str;

  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  if ((str = get_inventory(&player->inv)) == NULL)
    return (true);
  add_string(player->client, str);
  free(str);
  return (false);
}
