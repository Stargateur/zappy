/*
** player_see.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 30 22:40:36 2015 zwertv_e
** Last update Fri Jul  3 14:56:57 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"player.h"
#include	"map.h"

static size_t	find_nb_squares(size_t const accu, size_t const range)
{
  if (range == 0)
    return (accu);
  return (find_nb_squares(accu + 1 + 2 * range, range - 1));
}

static char	*concat(char const * const str1, char const * const str2)
{
  size_t	to_malloc;
  char		*res;

  to_malloc = 1;
  if (str1 != NULL)
    to_malloc += strlen(str1);
  if (str2 != NULL)
    to_malloc += strlen(str2);
  res = malloc(sizeof(char) * to_malloc);
  res[0] = '\0';
  if (str1 != NULL)
    res = strcat(res, str1);
  if (str2 != NULL)
    res = strcat(res, str2);
  return (res);
}

static void	find_squares(t_map const * const map,
			     t_player const * const player, t_coords *list,
			     size_t const range)
{
  size_t	i;
  int		tmp_h;
  int		tmp_w;

  i = 0;
  tmp_h = 0;
  while (tmp_h <= (int)player->range)
    {
      tmp_w = -((2 * tmp_h + 1) / 2);
      while (tmp_w <= (2 * tmp_h + 1) / 2)
	{
	  if (i < range)
	    {
	      list[i].x = get_x(map, player, tmp_h, tmp_w);
	      list[i].y = get_y(map, player, tmp_h, tmp_w);
	    }
	  tmp_w++;
	  i++;
	}
      tmp_h++;
    }
}

static bool	ffirst_write(char ** const res, char const * const ressource,
			     size_t const quantity, bool first_write)
{
  size_t	i;

  for (i = 0; i < quantity; i++)
    {
      if (first_write)
	{
	  (*res) = concat(*res, ressource);
	  first_write = false;
	}
      else
	{
	  (*res) = concat(*res, " ");
	  (*res) = concat(*res, ressource);
	}
    }
  return (first_write);
}

static bool	print_inv(char ** const res, t_inv const * const inv, bool first_write)
{
  first_write = ffirst_write(res, "linemate", inv->linemate, first_write);
  first_write = ffirst_write(res, "deraumere", inv->deraumere, first_write);
  first_write = ffirst_write(res, "sibur", inv->sibur, first_write);
  first_write = ffirst_write(res, "mendiane", inv->mendiane, first_write);
  first_write = ffirst_write(res, "phiras", inv->phiras, first_write);
  first_write = ffirst_write(res, "thystame", inv->thystame, first_write);
  first_write = ffirst_write(res, "nourriture", inv->food, first_write);
  return (first_write);
}

char		*player_view(t_game const * const game,
			    t_map const * const map,
			    t_player const * const player)
{
  size_t	range;
  size_t	i;
  t_coords	*list;
  t_player	*tmp;
  t_square	*tmp_square;
  bool		first_write;
  char		*res;

  res = NULL;
  if (!game || !player || !map)
    return (NULL);
  range = find_nb_squares(1, player->range);
  if ((list = malloc(sizeof(t_coords) * (range))) == NULL)
    return (NULL);
  find_squares(map, player, list, range);
  first_write = true;
  res = concat(res, "{");
  for (i = 0; i < range; i++)
    {
      if (i > 0)
	{
	  res = concat(res, ",");
	  first_write = false;
	}
      tmp_square = find_square(first_node(&map->items->node), list[i].x, list[i].y);
      if (tmp_square)
        first_write = print_inv(&res, &tmp_square->ressources, first_write);
      tmp = first_node(&game->player->node);
      while (tmp)
      	{
      	  if (player != tmp && tmp->coords.x == list[i].x && tmp->coords.y == list[i].y)
      	    {
      	      if (!first_write)
		res = concat(res, " ");
	      res = concat(res, "joueur");
      	    }
      	  tmp = tmp->node.next;
      	}
    }
  res = concat(res, "}");
  free(list);
  return (res);
}
