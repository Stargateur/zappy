/*
** map.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 21:15:02 2015 zwertv_e
** Last update Thu Jun 18 23:52:44 2015 zwertv_e
*/

#include		<string.h>
#include		"map.h"

static void		init_inv(t_inv *inv)
{
  inv->linemlate = 0;
  inv->deraumere = 0;
  inv->sibur = 0;
  inv->mendiane = 0;
  inv->phiras = 0;
  inv->thystame = 0;
  inv->food = 0;
}

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

void			init_player(t_player *player, size_t const x,
				    size_t const y, char const * const team)
{
  player->x = x;
  player->y = y;
  player->team = NULL;
  init_inv(&player->inv);
  if (team != NULL)
    player->team = strdup(team);
}

static t_squarre	*find_squarre(t_map const * const map,
				      size_t const x, size_t const y)
{
  t_squarre		*tmp;

  tmp = first_node(&map->items->node);
  while (tmp != NULL && tmp->x != x && tmp->y != y)
    tmp = tmp->node.next;
  return (tmp);
}

static void	        add_ressource(t_squarre *squarre, int const type, int const quantity)
{
  switch(type)
    {
    case linemlate:
      squarre->ressources.linemlate += quantity;
      break;
    case deraumere:
      squarre->ressources.deraumere += quantity;
      break;
    case sibur:
      squarre->ressources.sibur += quantity;
      break;
    case mendiane:
      squarre->ressources.mendiane += quantity;
      break;
    case phiras:
      squarre->ressources.phiras += quantity;
      break;
    case thystame:
      squarre->ressources.thystame += quantity;
      break;
    case food:
      squarre->ressources.food += quantity;
      break;
    };
}

static size_t		count_resources(t_squarre const * const squarre)
{
  size_t		res;

  res = 0;
  res += squarre->ressources.linemlate;
  res += squarre->ressources.deraumere;
  res += squarre->ressources.sibur;
  res += squarre->ressources.mendiane;
  res += squarre->ressources.phiras;
  res += squarre->ressources.thystame;
  res += squarre->ressources.food;
  return (res);
}

bool		        add_item(t_map *map, int const x, int const y, int const type)
{
  t_squarre		*squarre;

  if ((squarre = find_squarre(map, x, y)) != NULL)
    {
      add_ressource(squarre, type, 1);
      return (true);
    }
  if ((squarre = malloc(sizeof(t_squarre))) == NULL)
    return (false);
  squarre->x = x;
  squarre->y = y;
  init_inv(&squarre->ressources);
  add_ressource(squarre, type, 1);
  map->items = put_node(&map->items->node, &squarre->node);
  return (true);
}

bool			delete_item(t_map *map, int const x, int const y, int const type)
{
  t_squarre		*squarre;

  if ((squarre = find_squarre(map, x, y)) == NULL)
    return (false);
  add_ressource(squarre, type, -1);
  if (count_resources(squarre) == 0)
    map->items = sup_node(&squarre->node);
  return (true);
}
