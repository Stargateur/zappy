/*
** player_see.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Mon Jun 29 15:43:01 2015 zwertv_e
** Last update Tue Jun 30 18:46:46 2015 zwertv_e
*/

#include	"player.h"
#include	"map.h"

size_t		find_nb_squarres(size_t const accu, size_t const range)
{
  if (range == 0)
    return (accu);
  return (find_nb_squarres(accu + 1 + 2 * range, range - 1));
}

static size_t	get_x(t_map const * const map, t_player const * const player,
		      size_t const h, size_t const w)
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
      quantity = w;
      break;
    case SOUTH:
      break;
    case WEST:
      break;
    case EAST:
      break;
    };
  return (0);
}

static size_t	get_y(t_map const * const map, t_player const * const player,
		      size_t const h, size_t const w)
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
      quantity = w;
      break;
    case SOUTH:
      break;
    case WEST:
      break;
    case EAST:
      break;
    };
  return (0);
}

void		find_squarres(t_map const * const map,
			      t_player const * const player, t_squarre **list,
			      size_t const range)
{
  size_t	i;
  size_t	tmp_h;
  size_t	tmp_w;

  i = 0;
  tmp_h = 0;
  while (tmp_h < player->range)
    {
      tmp_w = 0;
      while (tmp_w < 2 * i + 1)
	{
	  list[i] = find_squarre(map, get_x(map, player, tmp_h, tmp_w), get_y(map, player, tmp_h, tmp_w));
	  tmp_w++;
	  i++;
	}
      tmp_h++;
    }
}

char		*player_view(t_map const * const map,
			    t_player const * const player)
{
  size_t	range;
  t_squarre	**list;

  if (!player || !map)
    return (NULL);
  if ((range = find_nb_squarres(1, player->range)) == NULL)
    return (NULL);
  list = malloc(sizeof(t_squarre *) * (range));
  find_squarres(map, player, list, range);
}
