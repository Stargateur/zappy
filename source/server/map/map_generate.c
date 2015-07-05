/*
** map_generate.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 15:51:14 2015 zwertv_e
** Last update Sun Jul  5 05:17:54 2015 Antoine Plaskowski
*/

#include	<time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"inv.h"
#include	"map.h"

static int	get_ressource_type(void)
{
  double	type;
  double	repart;
  double	rnd;

  rnd = (double)(random());
  repart = DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN;
  repart += DENSITY_PHI + DENSITY_THY + DENSITY_FOOD;
  type = fmod(rnd, repart);
  if (type < DENSITY_LIN)
    return (LINEMATE);
  else if (type < DENSITY_LIN + DENSITY_DER)
    return (DERAUMERE);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB)
    return (SIBUR);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN)
    return (MENDIANE);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN
	   + DENSITY_PHI)
    return (PHIRAS);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN
	   + DENSITY_PHI + DENSITY_THY)
    return (THYSTAME);
  return (FOOD);
}

static void	generate_ressources(t_map * const map, size_t const to_generate)
{
  size_t	x;
  size_t	y;
  int		type;

  if (to_generate > 0)
    {
      x = (size_t)random() % map->width;
      y = (size_t)random() % map->height;
      type = get_ressource_type();
      add_item(map, x, y, type);
      generate_ressources(map, to_generate - 1);
    }
}

static size_t	need_to_generate(t_map const * const map)
{
  double	available_size;

  available_size = (map->height * map->width);
  available_size *= DENSITY;
  if (map->nbr_item > (size_t)available_size)
    return (0);
  return ((size_t)(available_size - map->nbr_item));
}

bool		map_generate(t_map * const map)
{
  size_t	to_generate;

  if ((to_generate = need_to_generate(map)) > 0)
    {
      generate_ressources(map, to_generate);
      return (false);
    }
  return (true);
}
