/*
** inv.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:36:45 2015 zwertv_e
** Last update Thu Jul  2 16:02:47 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"inv.h"

void		init_inv(t_inv *inv)
{
  inv->linemate = 0;
  inv->deraumere = 0;
  inv->sibur = 0;
  inv->mendiane = 0;
  inv->phiras = 0;
  inv->thystame = 0;
  inv->food = 0;
}

static size_t	*get_inv_ressource(t_inv const * const inv, int const type)
{
  size_t	*ressource;

  ressource = NULL;
  switch(type)
    {
    case LINEMATE:
      ressource = &inv->linemate;
      break;
    case DERAUMERE:
      ressource = &inv->deraumere;
      break;
    case SIBUR:
      ressource = &inv->sibur;
      break;
    case MENDIANE:
      ressource = &inv->mendiane;
      break;
    case PHIRAS:
      ressource = &inv->phiras;
      break;
    case THYSTAME:
      ressource = &inv->thystame;
      break;
    case FOOD:
      ressource = &inv->food;
      break;
    };
  return (ressource);
}

bool	        add_ressource(t_inv * const inv, int const type,
			      size_t const quantity, bool add)
{
  size_t	*ressource;

  ressource = get_inv_ressource(inv, type);
  if (!ressource)
    return (false);
  if (!add && *ressource < quantity)
    return (false);
  if (add)
    *ressource += quantity;
  else
    *ressource -= quantity;
  return (true);
}

size_t		count_ressources(t_inv const * const inv)
{
  size_t		res;

  res = 0;
  res += inv->linemate;
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

  to_malloc = snprintf(NULL, 0, "linemate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu", inv->linemate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  res = malloc(to_malloc + 1);
  snprintf(res, to_malloc + 1, "linemate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu", inv->linemate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  return (res);
}
