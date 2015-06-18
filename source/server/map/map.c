/*
** map.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 21:15:02 2015 zwertv_e
** Last update Thu Jun 18 23:36:51 2015 zwertv_e
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

void		        init_map(t_map *map, int height, int width)
{
  map->height = height;
  map->width = width;
  map->items = NULL;
  map->players = NULL;
}

void			free_map(t_map *map)
{
  free_all_node(&map->players.node);
  free_all_node(&map->items.node);
}

void			init_player(int const x, int const y,
				    char const * const team)
{
  player->x = x;
  player->y = y;
  player->team = NULL;
  init_inv(&player->inv);
  if (team != NULL)
    player->team = strdup(team);
  return (true);
}

static t_squarre	*find_squarre(t_map const * const map,
				      int const x, int const y)
{
  t_item		*tmp;

  tmp = first_node(&map->items.node);
  while (tmp != NULL && tmp.x != x && tmp.y != y)
    tmp = tmp.node->next;
  return (tmp);
}

static void	        add_ressource(t_squarre *squarre, int const type, int const quantity)
{
  switch(type)
    {
    case linemlate:
      squarre->inv.linemlate += quantity;
      break;
    case deraumere:
      squarre->inv.deraumere += quantity;
      break;
    case sibur:
      squarre->inv.sibur += quantity;
      break;
    case mendiane:
      squarre->inv.mendiane += quantity;
      break;
    case phiras:
      squarre->inv.phiras += quantity;
      break;
    case thystame:
      squarre->inv.thystame += quantity;
      break;
    case food:
      squarre->inv.food += quantity;
      break;
    };
}

static size_t		count_resources(t_squarre const * const squarre)
{
  size_t		res;

  res = 0;
  res += squarre->inv.linemlate;
  res += squarre->inv.deraumere;
  res += squarre->inv.sibur;
  res += squarre->inv.mendiane;
  res += squarre->inv.phiras;
  res += squarre->inv.thystame;
  res += squarre->inv.food;
  return (res);
}

bool		        add_item(t_map *map, int const x, int const y, int const type)
{
  t_item		*squarre;

  if ((squarre = find_squarre(map, x, y)) != NULL)
    {
      add_ressource(squarre, type);
      return (true);
    }
  if ((squarre = malloc(sizeof(t_squarre))) == NULL)
    return (false);
  squarre->x = x;
  squarre->y = y;
  init_inv(squarre->inv);
  add_ressource(squarre, type, 1);
  map->items = put_node(&map->items.node, &squarre.node);
  return (true);
}

bool			delete_item(t_map *map, int const x, int const y, int const type)
{
  t_item		*squarre;

  if ((squarre = find_squarre(map, x, y)) == NULL)
    return (false);
  add_ressource(squarre, type, -1);
  if (count_resources(squarre) == 0)
    map->items = sup_node(squarre);
  return (true);
}
