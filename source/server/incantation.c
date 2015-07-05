/*
** incantation.c for incantation in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 17:59:42 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"game.h"
#include	"player.h"
#include	"incantation.h"
#include	"message.h"

bool		incantation_en_cours(t_player *player)
{
  if (player == NULL)
    return (true);
  if (player->action == NULL)
    return (true);
  if (player->action->cmd == NULL)
    return (true);
  if (player->action->cmd->type == INCANTATION)
    add_string(player->client, INCANTATION_EN_COURS);
  return (false);
}

bool		incantation(t_game *game, t_player *player, char *arg)
{
  char		*str;

  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  player_levelup(game, &game->map, player, true);
  str = malloc_vsnprintf("niveau actuel : %lu\n", player->range);
  add_string(player->client, str);
  free(str);
  return (false);
}
