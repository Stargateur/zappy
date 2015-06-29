/*
** map.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 21:15:02 2015 zwertv_e
** Last update Mon Jun 29 16:51:42 2015 zwertv_e
*/

#include		<stdlib.h>
#include		"map.h"

void		        init_map(t_map *map, size_t height, size_t width)
{
  map->height = height;
  map->width = width;
  map->items = NULL;
}

void			free_map(t_map *map)
{
  free_all_node(&map->items->node);
}

static t_squarre	*find_squarre(t_squarre const * const squarre,
				      size_t const x, size_t const y)
{
  if (squarre == NULL)
    return (NULL);
  if (squarre->x == x && squarre->y == y)
    return (squarre);
  return (find_squarre(squarre->node.next, x, y));
}

bool		        add_item(t_map *map, size_t const x, size_t const y,
				 int const type)
{
  t_squarre		*squarre;

  if ((squarre = find_squarre(first_node(&map->items->node), x, y)) != NULL)
    {
      add_ressource(&squarre->ressources, type, 1);
      return (true);
    }
  if ((squarre = malloc(sizeof(t_squarre))) == NULL)
    return (false);
  squarre->x = x;
  squarre->y = y;
  init_inv(&squarre->ressources);
  add_ressource(&squarre->ressources, type, 1);
  map->items = put_node(&map->items->node, &squarre->node);
  return (true);
}

bool			delete_item(t_map *map, size_t const x, size_t const y,
				    int const type)
{
  t_squarre		*squarre;

  if ((squarre = find_squarre(first_node(&map->items->node), x, y)) == NULL)
    return (false);
  add_ressource(&squarre->ressources, type, -1);
  if (count_ressources(&squarre->ressources) == 0)
    map->items = sup_node(&squarre->node);
  return (true);
}
