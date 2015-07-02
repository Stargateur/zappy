/*
** player_see.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 30 22:40:36 2015 zwertv_e
** Last update Thu Jul  2 16:03:29 2015 zwertv_e
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"player.h"
#include	"map.h"

static size_t	find_nb_squares(size_t const accu, size_t const range)
{
  if (range == 0)
    return (accu);
  return (find_nb_squares(accu + 1 + 2 * range, range - 1));
}

static size_t	get_x(t_map const * const map, t_player const * const player,
		      int const h, int const w)
{
  bool		addition;
  size_t        pos;
  size_t	quantity;

  addition = true;
  pos = player->coords.x;
  quantity = 0;
  switch (player->dir)
    {
    case NORTH:
      if (w < 0)
	{
	  quantity = (size_t)(-w);
	  addition = false;
	}
      else
	{
	  quantity = (size_t)w;
	  addition = true;
	}
      break;
    case SOUTH:
      if (w < 0)
	{
	  quantity = (size_t)(-w);
	  addition = true;
	}
      else
	{
	  quantity = (size_t)w;
	  addition = false;
	}
      break;
    case WEST:
      quantity = (size_t)h;
      addition = false;
      break;
    case EAST:
      quantity = (size_t)h;
      addition = true;
      break;
    };
  while (quantity > 0)
    {
      if (addition)
	pos = next_x(map, pos);
      else
	pos = prev_x(map, pos);
      quantity--;
    }
  return (pos);
}

static size_t	get_y(t_map const * const map, t_player const * const player,
		      int const h, int const w)
{
  bool		addition;
  size_t        pos;
  size_t	quantity;

  addition = true;
  pos = player->coords.y;
  quantity = 0;
  switch (player->dir)
    {
    case NORTH:
      quantity = (size_t)h;
      addition = false;
      break;
    case SOUTH:
      quantity = (size_t)h;
      addition = true;
      break;
    case WEST:
      if (w < 0)
	{
	  quantity = (size_t)(-w);
	  addition = false;
	}
      else
	{
	  quantity = (size_t)w;
	  addition = true;
	}
      break;
    case EAST:
      if (w < 0)
	{
	  quantity = (size_t)(-w);
	  addition = true;
	}
      else
	{
	  quantity = (size_t)w;
	  addition = false;
	}
      break;
    };
  while (quantity > 0)
    {
      if (addition)
	pos = next_y(map, pos);
      else
	pos = prev_y(map, pos);
      quantity--;
    }
  return (pos);
}

void		find_squares(t_map const * const map,
			      t_player const * const player, t_coords *list,
			      size_t const range)
{
  size_t	i;
  int		tmp_h;
  int		tmp_w;

  i = 0;
  tmp_h = 0;
  while (tmp_h <= (int)player->range)
    {
      tmp_w = -((2 * tmp_h + 1) / 2);
      while (tmp_w <= (2 * tmp_h + 1) / 2)
	{
	  if (i < range)
	    {
	      list[i].x = get_x(map, player, tmp_h, tmp_w);
	      list[i].y = get_y(map, player, tmp_h, tmp_w);
	    }
	  tmp_w++;
	  i++;
	}
      tmp_h++;
    }
}

static bool	ffirst_write(char const * const ressource,
			     size_t const quantity, bool first_write)
{
  size_t	i;

  for (i = 0; i < quantity; i++)
    {
      if (first_write)
	{
	  printf("%s", ressource);
	  first_write = false;
	}
      else
	printf(" %s", ressource);
    }
  return (first_write);
}

static bool	print_inv(t_inv const * const inv, bool first_write)
{
  size_t	i;

  first_write = ffirst_write("linemate", inv->linemate, first_write);
  first_write = ffirst_write("deraumere", inv->deraumere, first_write);
  first_write = ffirst_write("sibur", inv->sibur, first_write);
  first_write = ffirst_write("mendiane", inv->mendiane, first_write);
  first_write = ffirst_write("phiras", inv->phiras, first_write);
  first_write = ffirst_write("thystame", inv->thystame, first_write);
  first_write = ffirst_write("nourriture", inv->food, first_write);
  return (first_write);
}

char		*player_view(t_game const * const game,
			     t_map const * const map,
			    t_player const * const player)
{
  size_t	range;
  size_t	i;
  t_coords	*list;
  t_player	*tmp;
  t_square	*tmp_square;
  bool		first_write;

  if (!player || !map)
    return (NULL);
  range = find_nb_squares(1, player->range);
  if ((list = malloc(sizeof(t_coords) * (range))) == NULL)
    return (NULL);
  find_squares(map, player, list, range);
  first_write = true;
  printf("{");
  for (i = 0; i < range; i++)
    {
      if (i > 0)
	{
	  printf(",");
	  first_write = false;
	}
      tmp_square = find_square(first_node(&map->items->node), list[i].x, list[i].y);
      if (tmp_square)
        first_write = print_inv(&tmp_square->ressources, first_write);
      tmp = first_node(&game->player->node);
      while (tmp)
      	{
      	  if (player != tmp && tmp->coords.x == list[i].x && tmp->coords.y == list[i].y)
      	    {
      	      if (!first_write)
      		printf(" ");
      	      printf("joueur");
      	    }
      	  tmp = tmp->node.next;
      	}
    }
  printf("}\n");
  free(list);
  return (NULL);
}
