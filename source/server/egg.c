/*
** egg.c for egg in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:43:36 2015 Antoine Plaskowski
** Last update Sun Jul  5 04:57:29 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"game.h"
#include	"player.h"
#include	"egg.h"

t_egg		*add_egg(t_egg *list, t_coord *coord, size_t t)
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
  return (put_node(&list->node, &egg->node));
}

static bool	pop_egg(t_egg *egg, t_time act, t_time *timeout)
{
}

t_egg		*hatches_egg(t_egg *list, size_t t)
{
  t_egg		*egg;
  t_egg		*egg2;
  t_time	act;
  t_time	timeout;

  if (clock_gettime(CLOCK_MONOTONIC_RAW, &act) == -1)
    {
      perror("clock_gettime : ");
      return (NULL);
    }
  egg = first_node(&list->node);
  while (egg != NULL)
    {
      egg2 = egg->node.next;
      if (pop_egg(egg, act, &timeout) == true)
	{
	  printf("je timeout un egg\n");
	  list = sup_egg(egg);
	}
      egg = egg2;
    }
}

bool		egg(t_game *game, t_player *player, char *arg)
{
  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  game->egg = add_egg(game->egg, &player->coord, game->option.t);
  return (false);
}
