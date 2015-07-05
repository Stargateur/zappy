/*
** inv.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jul  2 18:59:57 2015 zwertv_e
** Last update Sun Jul  5 05:56:03 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"inv.h"

static t_str_type_inv	g_str_type[] =
  {
    {"linemate", LINEMATE, sizeof("linemate") - 1},
    {"deraumere", DERAUMERE, sizeof("deraumere") - 1},
    {"sibur", SIBUR, sizeof("sibur") - 1},
    {"mendiane", MENDIANE, sizeof("mendiane") - 1},
    {"phiras", PHIRAS, sizeof("phiras") - 1},
    {"thystame", THYSTAME, sizeof("thystame") - 1},
    {"nourriture", FOOD, sizeof("nourriture") - 1}
  };

static size_t	g_s_str_type = sizeof(g_str_type) / sizeof(*g_str_type);

t_t_inv		get_type_inv(char const * const str)
{
  size_t	i;

  if (str == NULL)
    return (NONE);
  for (i = 0; i < g_s_str_type; i++)
    {
      if (strncasecmp(str, g_str_type[i].str, g_str_type[i].len) == 0)
	return (g_str_type[i].type);
    }
  return (NONE);
}

t_inv		*init_inv(t_inv *inv)
{
  if (inv == NULL)
    return (NULL);
  inv->linemate = 0;
  inv->deraumere = 0;
  inv->sibur = 0;
  inv->mendiane = 0;
  inv->phiras = 0;
  inv->thystame = 0;
  inv->food = 0;
  return (inv);
}

bool		add_ressource(t_inv * const inv, int const type,
			      size_t const quantity, bool add)
{
  if (inv == NULL)
    return (true);
  if (type > FOOD)
    return (true);
  if (add == true)
    (&inv->linemate)[type] += quantity;
  else
    {
      if ((&inv->linemate)[type] < quantity)
	return (true);
      (&inv->linemate)[type] -= quantity;
    }
  return (false);
}

size_t		count_ressources(t_inv const * const inv)
{
  size_t	res;

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

  to_malloc = snprintf(NULL, 0, "{linemate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu}\n", inv->linemate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  res = malloc(sizeof(char) * (to_malloc + 1));
  snprintf(res, to_malloc + 1, "{linemate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu}\n", inv->linemate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  return (res);
}
