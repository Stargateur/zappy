/*
** map_generate.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 15:51:14 2015 zwertv_e
** Last update Wed Jul  1 13:58:12 2015 zwertv_e
*/

#include	<time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"inv.h"
#include	"map.h"

static int	get_ressource_type(void)
{
  int tmp = random();
  int		type;
  int		repart;

  repart = DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN;
  repart += DENSITY_PHI + DENSITY_THY + DENSITY_FOOD;
  type = tmp % repart;
  if (type < DENSITY_LIN)
    return (linemlate);
  else if (type < DENSITY_LIN + DENSITY_DER)
    return (deraumere);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB)
    return (sibur);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN)
    return (mendiane);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN +
	   DENSITY_PHI)
    return (phiras);
  else if (type < DENSITY_LIN + DENSITY_DER + DENSITY_SIB + DENSITY_MEN +
	   DENSITY_PHI + DENSITY_THY)
    return (thystame);
  return (food);
}

static void	generate_ressources(t_map * const map, size_t const to_generate)
{
  size_t	x;
  size_t	y;
  int		type;

  if (to_generate > 0)
    {
      x = random() % map->width;
      y = random() % map->height;
      type = get_ressource_type();
      add_item(map, x, y, type);
      generate_ressources(map, to_generate - 1);
    }
}

static size_t	need_to_generate(t_map const * const map)
{
  double	total_ressources;
  double	available_size;
  t_square	*tmp;

  total_ressources = 0;
  tmp = first_node(&map->items->node);
  while (tmp != NULL)
    {
      total_ressources += count_ressources(&tmp->ressources);
      tmp = tmp->node.next;
    }
  available_size = (map->height * map->width) / 8;
  available_size *= DENSITY;
  if (total_ressources > available_size)
    return (0);
  return ((size_t)(available_size - total_ressources));
}

bool		map_generate(t_map * const map)
{
  size_t	to_generate;

  if ((to_generate = need_to_generate(map)) > 0)
    {
      generate_ressources(map, to_generate);
      return (true);
    }
  printf("Max ressources reached !\n");
  return (false);
}
