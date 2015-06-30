/*
** game.c for game in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:16:27 2015 Antoine Plaskowski
** Last update Tue Jun 30 17:12:30 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"utils.h"
#include	"game.h"
#include	"opt.h"

t_game		*init_game(t_game * const game)
{
  size_t	i;

  if (game == NULL)
    return (NULL);
  game->size_team = len_tab((void **)opt.team);
  game->team = malloc(sizeof(*game->team) * (game->size_team + 1));
  if (game->team == NULL)
    return (NULL);
  for (i = 0; i < game->size_team; i++)
    {
      game->team[i].connect = 0;
      game->team[i].connect_max = opt.c;
      game->team[i].team = opt.team[i];
    }
  return (game);
}
