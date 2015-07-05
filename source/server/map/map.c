/*
** map.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 21:15:02 2015 zwertv_e
** Last update Sun Jul  5 05:15:24 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"map.h"

t_map		*init_map(t_map *map, size_t height, size_t width)
{
  if (map == NULL)
    return (NULL);
  map->height = height;
  map->width = width;
  map->items = NULL;
  map->nbr_item = 0;
  return (map);
}

void		free_map(t_map *map)
{
  free_all_node(&map->items->node);
  map->items = NULL;
}

t_square	*find_square(t_square *square, size_t const x, size_t const y)
{
  if (square == NULL)
    return (NULL);
  if (square->coord.x == x && square->coord.y == y)
    return (square);
  return (find_square(square->node.next, x, y));
}

bool		add_item(t_map *map, size_t const x, size_t const y,
			 int const type)
{
  t_square	*square;

  if ((square = find_square(first_node(&map->items->node), x, y)) != NULL)
    {
      add_ressource(&square->ressources, type, 1, true);
      map->nbr_item++;
      return (false);
    }
  if ((square = malloc(sizeof(t_square))) == NULL)
    return (true);
  map->nbr_item++;
  square->coord.x = x;
  square->coord.y = y;
  init_inv(&square->ressources);
  add_ressource(&square->ressources, type, 1, true);
  map->items = put_node(&map->items->node, &square->node);
  return (false);
}

bool		delete_item(t_map *map, size_t const x, size_t const y,
			    int const type)
{
  t_square	*square;

  if ((square = find_square(first_node(&map->items->node), x, y)) == NULL)
    return (true);
  if (add_ressource(&square->ressources, type, 1, false) == false)
    map->nbr_item--;
  if (count_ressources(&square->ressources) == 0)
    map->items = sup_node(&square->node);
  return (false);
}
