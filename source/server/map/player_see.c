/*
** player_see.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 30 22:40:36 2015 zwertv_e
** Last update Wed Jul  1 13:49:04 2015 zwertv_e
*/

#include	<stdlib.h>
#include	"player.h"
#include	"map.h"

size_t		find_nb_squares(size_t const accu, size_t const range)
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

void		find_squares(t_map const * const map,
			      t_player const * const player, t_coords *list,
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
	  list[i].x = get_x(map, player, tmp_h, tmp_w);
	  list[i].y = get_y(map, player, tmp_h, tmp_w);
	  tmp_w++;
	  i++;
	}
      tmp_h++;
    }
}

char		*player_view(t_game const * const game,
			     t_map const * const map,
			    t_player const * const player)
{
  size_t	range;
  size_t	i;
  t_coords	*list;
  t_player	*tmp;
  bool		first_write;

  if (!player || !map)
    return (NULL);
  if ((range = find_nb_squares(0, player->range)) < 0)
    return (NULL);
  if ((list = malloc(sizeof(t_coords) * (range))) == NULL)
    return (NULL);
  find_squares(map, player, list, range);
  first_write = true;
  for (i = 0; i < range; i++)
    {
      printf("%lu %lu\n", list[i].x, list[i].y);
      /* tmp = first_node(&game->player->node); */
      /* while (tmp) */
      /* 	{ */
      /* 	  if (player != tmp && tmp->coords.x == ) */
      /* 	    { */
      /* 	      if (!first_write) */
      /* 		printf(" "); */
      /* 	      printf("player"); */
      /* 	    } */
      /* 	  tmp = tmp->node.next; */
      /* 	} */
    }
  free(list);
  return (NULL);
}
