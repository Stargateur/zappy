/*
** player_see.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 30 22:40:36 2015 zwertv_e
** Last update Sun Jul  5 12:07:25 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"player.h"
#include	"map.h"

static void	ffirst_write(char ** const res, char const * const ressource,
			     size_t const quantity)
{
  size_t	i;

  for (i = 0; i < quantity; i++)
    {
      if ((*res) == NULL || (*res)[1] == '\0')
	(*res) = concat(*res, ressource, true);
      else
	{
	  (*res) = concat(*res, " ", true);
	  (*res) = concat(*res, ressource, true);
	}
    }
}

static void	print_inv(char ** const res, t_inv const * const inv)
{
  ffirst_write(res, "linemate", inv->linemate);
  ffirst_write(res, "deraumere", inv->deraumere);
  ffirst_write(res, "sibur", inv->sibur);
  ffirst_write(res, "mendiane", inv->mendiane);
  ffirst_write(res, "phiras", inv->phiras);
  ffirst_write(res, "thystame", inv->thystame);
  ffirst_write(res, "nourriture", inv->food);
}

static char	*print_players(t_game const * const game,
			       t_player const * const player,
			       t_coord const * const list,
			       char *res)
{
  t_player	*tmp;

  tmp = first_node(&game->player->node);
  while (tmp != NULL)
    {
      if (player != tmp && tmp->coord.x == (*list).x &&
	  tmp->coord.y == (*list).y)
	{
	  if (res != NULL && res[1] != '\0')
	    res = concat(res, " ", true);
	  res = concat(res, "joueur", true);
	}
      tmp = tmp->node.next;
    }
  return (res);
}

char		*player_view(t_game const * const game,
			    t_map const * const map,
			    t_player const * const player)
{
  size_t	range;
  size_t	i;
  t_coord	*list;
  t_square	*tmp_square;
  char		*res;

  if (game == NULL || player == NULL || map == NULL)
    return (NULL);
  range = find_nb_squares(1, player->range);
  if ((list = malloc(sizeof(t_coord) * (range))) == NULL)
    return (NULL);
  find_squares(map, player, list, range);
  res = concat(NULL, "{", false);
  for (i = 0; i < range; i++)
    {
      res = (i > 0) ? (concat(res, ",", true)) : (res);
      tmp_square = find_square(first_node(&map->items->node),
			       list[i].x, list[i].y);
      if (tmp_square != NULL)
        print_inv(&res, &tmp_square->ressources);
      res = print_players(game, player, &(list[i]), res);
    }
  res = concat(res, "}\n", true);
  free(list);
  return (res);
}
