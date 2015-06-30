/*
** player_see.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 30 22:40:36 2015 zwertv_e
** Last update Wed Jul  1 01:29:46 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"player.h"
#include	"map.h"

size_t		find_nb_squarres(size_t const accu, size_t const range)
{
  if (range == 0)
    return (accu);
  return (find_nb_squarres(accu + 1 + 2 * range, range - 1));
}

static size_t	get_x(t_map const * const map, t_player const * const player,
		      int const h, int const w)
{
  bool		addition;
  size_t        pos;
  size_t	quantity;

  addition = true;
  pos = player->x;
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
  pos = player->y;
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
	  quantity = -w;
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
	  quantity = -w;
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

void		find_squarres(t_map const * const map,
			      t_player const * const player, t_squarre **list,
			      size_t const range)
{
  size_t	i;
  int		tmp_h;
  int		tmp_w;

  i = 0;
  tmp_h = 0;
  while (tmp_h <= player->range)
    {
      tmp_w = -((2 * tmp_h + 1) / 2);
      while (tmp_w <= (2 * tmp_h + 1) / 2)
	{
	  list[i] = find_squarre(first_node(&map->items->node), get_x(map, player, tmp_h, tmp_w), get_y(map, player, tmp_h, tmp_w));
	  tmp_w++;
	  i++;
	}
      tmp_h++;
    }
}

static size_t	count_malloc_space(t_squarre const * const squarre)
{
  int		to_malloc;

  to_malloc = 0;
  /* to_malloc = snprintf(0, NULL, "%s"); */
  return (0);
}

char		*player_view(t_game const * const game,
			     t_map const * const map,
			    t_player const * const player)
{
  size_t	range;
  size_t	needed_space;
  size_t	i;
  t_squarre	**list;

  if (!player || !map)
    return (NULL);
  if ((range = count_malloc_space(player->range)) < 0)
    return (NULL);
  if ((list = malloc(sizeof(t_squarre *) * (range))) == NULL)
    return (NULL);
  find_squarres(map, player, list, range);
  needed_space = 0;
  for (i = 0; i < range; i++)
    needed_space += count_inventory_space();
  return (NULL);
}
