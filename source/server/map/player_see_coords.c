/*
** player_see_coords.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Jul  3 14:57:08 2015 zwertv_e
** Last update Fri Jul  3 15:09:42 2015 zwertv_e
*/

#include	"map.h"
#include	"player.h"

static size_t	get_x(t_map const * const map, t_player const * const player,
		      int const h, int const w)
{
  bool		addition;
  size_t	pos;
  size_t	quantity;

  addition = true;
  pos = player->coords.x;
  quantity = (size_t)h;
  if (player->dir == NORTH || player->dir == SOUTH)
    quantity = (w < 0) ? ((size_t)(-w)) : ((size_t)w);
  if (player->dir == NORTH)
    addition = (w < 0) ? (false) : (true);
  else if (player->dir == SOUTH)
    addition = (w < 0) ? (true) : (false);
  else if (player->dir == WEST)
    addition = false;
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
  size_t	pos;
  size_t	quantity;

  addition = true;
  pos = player->coords.y;
  quantity = (size_t)h;
  if (player->dir == WEST || player->dir == EAST)
    quantity = (w < 0) ? ((size_t)(-w)) : ((size_t)w);
  if (player->dir == NORTH)
    addition = false;
  else if (player->dir == WEST)
    addition = (w < 0) ? (false) : (true);
  else if (player->dir == EAST)
    addition = (w < 0) ? (true) : (false);
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
