/*
** egg.c for egg in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 19:35:04 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"game.h"
#include	"player.h"
#include	"message.h"
#include	"egg.h"

t_egg		*add_egg(t_egg *list, t_coord *coord, t_team *team, size_t t)
{
  t_egg		*egg;

  if (coord == NULL)
    return (NULL);
  if ((egg = malloc(sizeof(*egg))) == NULL)
    return (NULL);
  if (clock_gettime(CLOCK_MONOTONIC_RAW, &egg->time) == -1)
    {
      free(egg);
      perror("clock_gettime : ");
      return (NULL);
    }
  if (time_div(&egg->timeout, 600, t) == true)
    return (NULL);
  egg->coord = *coord;
  egg->team = team;
  return (put_node(&list->node, &egg->node));
}

static bool	pop_egg(t_game *game, t_egg *egg, t_time act, t_time *timeout)
{
  t_player	*player;

  if (time_sub(&act, &egg->time) == true)
    return (true);
  if (time_small(&act, timeout) == true)
    return (false);
  if (egg->team == NULL)
    return (true);
  egg->team->connect_max++;
  player = init_player(&game->map, egg->team, egg->coord.x, egg->coord.y);
  game->player = put_node(&game->player->node, &player->node);
  return (true);
}

bool		hatches_egg(t_game *game)
{
  t_egg		*egg;
  t_egg		*egg2;
  t_time	act;

  if (game == NULL)
    return (true);
  if (clock_gettime(CLOCK_MONOTONIC_RAW, &act) == -1)
    {
      perror("clock_gettime : ");
      return (true);
    }
  egg = first_node(&game->egg->node);
  while (egg != NULL)
    {
      egg2 = egg->node.next;
      if (pop_egg(game, egg, act, &egg->timeout) == true)
	game->egg = sup_node(&egg->node);
      egg = egg2;
    }
  return (false);
}

bool		egg(t_game *game, t_player *player, char *arg)
{
  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  game->egg = add_egg(game->egg, &player->coord, player->team, game->option.t);
  add_string(player->client, OK);
  return (false);
}

