/*
** game.c for game in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:16:27 2015 Antoine Plaskowski
** Last update Sun Jul  5 19:41:42 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<string.h>
#include	"utils.h"
#include	"game.h"
#include	"option.h"
#include	"map.h"

static bool	game_option(t_game *game, char **argv, int const argc)
{
  size_t	i;

  if (get_option(&game->option, argv, argc) == true)
    return (true);
  game->size_team = len_tab((void **)game->option.team);
  if (game->option.n != NULL)
    game->team = malloc(sizeof(*game->team) * (game->size_team + 1));
  else
    game->team = malloc(sizeof(*game->team) * game->size_team);
  if (game->team == NULL)
    return (true);
  for (i = 0; i < game->size_team; i++)
    {
      game->team[i].connect_max = game->option.c;
      game->team[i].len_team = strlen(game->option.team[i]);
      game->team[i].team = game->option.team[i];
    }
  if (game->option.n != NULL)
    {
      game->team[i].connect_max = game->option.c;
      game->team[i].len_team = strlen(game->option.n);
      game->team[i].team = game->option.n;
      game->size_team++;
    }
  return (false);
}

t_game		*init_game(t_game * const game, char **argv, int const argc)
{
  if (game == NULL)
    return (NULL);
  if (game_option(game, argv, argc) == true)
    return (NULL);
  if (pthread_mutex_init(&game->mutex, NULL) < 0)
    return (NULL);
  pthread_mutex_unlock(&game->mutex);
  game->player = NULL;
  game->egg = NULL;
  time_div(&game->food, FOOD_BY_TIME, game->option.t);
  init_map(&game->map, game->option.x, game->option.y);
  map_generate(&game->map);
  return (game);
}

void		delete_game(t_game * const game)
{
  if (game == NULL)
    return;
  while (game->player != NULL)
    game->player = delete_player(game->player);
  while (game->egg != NULL)
    game->egg = sup_node(&game->egg->node);
  free(game->team);
  free_map(&game->map);
}
