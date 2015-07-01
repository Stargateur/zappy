/*
** game.c for game in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:16:27 2015 Antoine Plaskowski
** Last update Wed Jul  1 04:45:26 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<string.h>
#include	"utils.h"
#include	"game.h"
#include	"opt.h"

t_game		*init_game(t_game * const game, char **argv, int const argc)
{
  size_t	i;

  if (game == NULL)
    return (NULL);
  if (get_opt(&game->opt, argv, argc) == true)
    return (NULL);
  game->player = NULL;
  game->size_team = len_tab((void **)game->opt.team);
  game->team = malloc(sizeof(*game->team) * (game->size_team + 1));
  if (game->team == NULL)
    return (NULL);
  init_map(&game->map, game->opt.x, game->opt.y);
  map_generate(&game->map);
  for (i = 0; i < game->size_team; i++)
    {
      game->team[i].connect = 0;
      game->team[i].connect_max = game->opt.c;
      game->team[i].len_team = strlen(game->opt.team[i]);
      game->team[i].team = game->opt.team[i];
    }
  return (game);
}
