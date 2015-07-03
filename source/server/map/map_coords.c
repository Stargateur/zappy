/*
** map_coord.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Mon Jun 29 16:03:18 2015 zwertv_e
** Last update Fri Jul  3 14:44:31 2015 zwertv_e
*/

#include	"map.h"

size_t		prev_x(t_map const * const map, size_t x)
{
  if (x == 0)
    return (map->width - 1);
  return (x - 1);
}

size_t		next_x(t_map const * const map, size_t x)
{
  if (x == map->width - 1)
    return (0);
  return (x + 1);
}

size_t		prev_y(t_map const * const map, size_t y)
{
  if (y == 0)
    return (map->height - 1);
  return (y - 1);
}

size_t		next_y(t_map const * const map, size_t y)
{
  if (y == map->height - 1)
    return (0);
  return (y + 1);
}
