/*
** game.c for game in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:16:27 2015 Antoine Plaskowski
** Last update Mon Jun 29 16:14:29 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"utils.h"
#include	"game.h"
#include	"opt.h"

t_game		*init_game(t_game *game)
{
  size_t	len;
  size_t	i;

  if (game == NULL)
    return (NULL);
  len = len_tab((void **)opt.team);
  game->connect_nbr = malloc(sizeof(*game->connect_nbr) * (len + 1));
  if (game->connect_nbr != NULL)
    return (NULL);
  for (i = 0; i < len; i++)
    game->connect_nbr[i] = opt.c;
  return (game);
}
