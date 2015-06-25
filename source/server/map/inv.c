/*
** inv.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:36:45 2015 zwertv_e
** Last update Thu Jun 25 22:00:32 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"inv.h"

void		init_inv(t_inv *inv)
{
  inv->linemlate = 0;
  inv->deraumere = 0;
  inv->sibur = 0;
  inv->mendiane = 0;
  inv->phiras = 0;
  inv->thystame = 0;
  inv->food = 0;
}

void	        add_ressource(t_inv * const inv, int const type,
			      int const quantity)
{
  switch(type)
    {
    case linemlate:
      inv->linemlate += quantity;
      break;
    case deraumere:
      inv->deraumere += quantity;
      break;
    case sibur:
      inv->sibur += quantity;
      break;
    case mendiane:
      inv->mendiane += quantity;
      break;
    case phiras:
      inv->phiras += quantity;
      break;
    case thystame:
      inv->thystame += quantity;
      break;
    case food:
      inv->food += quantity;
      break;
    };
}

size_t		count_ressources(t_inv const * const inv)
{
  size_t		res;

  res = 0;
  res += inv->linemlate;
  res += inv->deraumere;
  res += inv->sibur;
  res += inv->mendiane;
  res += inv->phiras;
  res += inv->thystame;
  res += inv->food;
  return (res);
}

char		*get_inventory(t_inv const * const inv)
{
  char		*res;
  int		to_malloc;

  to_malloc = snprintf(NULL, 0, "linemlate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu", inv->linemlate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  res = malloc(to_malloc + 1);
  snprintf(res, to_malloc + 1, "linemlate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu", inv->linemlate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  return (res);
}
