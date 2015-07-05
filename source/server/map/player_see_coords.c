/*
** player_see_coords.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Jul  3 14:57:08 2015 zwertv_e
** Last update Sun Jul  5 12:03:43 2015 Antoine Plaskowski
*/

#include	"map.h"
#include	"player.h"

size_t		get_x(t_map const * const map, t_player const * const player,
		      int const h, int const w)
{
  bool		addition;
  size_t	pos;
  size_t	quantity;

  pos = player->coord.x;
  quantity = (size_t)h;
  if (player->dir == NORTH || player->dir == SOUTH)
    quantity = (w < 0) ? ((size_t)(-w)) : ((size_t)w);
  if (player->dir == NORTH)
    addition = (w < 0) ? (false) : (true);
  else if (player->dir == SOUTH)
    addition = (w < 0) ? (true) : (false);
  else if (player->dir == WEST)
    addition = false;
  else
    addition = true;
  while (quantity > 0)
    {
      if (addition == true)
	pos = next_x(map, pos);
      else
	pos = prev_x(map, pos);
      quantity--;
    }
  return (pos);
}

size_t		get_y(t_map const * const map, t_player const * const player,
		      int const h, int const w)
{
  bool		addition;
  size_t	pos;
  size_t	quantity;

  pos = player->coord.y;
  quantity = (size_t)h;
  if (player->dir == WEST || player->dir == EAST)
    quantity = (w < 0) ? ((size_t)(-w)) : ((size_t)w);
  if (player->dir == NORTH)
    addition = true;
  else if (player->dir == WEST)
    addition = (w < 0) ? (false) : (true);
  else if (player->dir == EAST)
    addition = (w < 0) ? (true) : (false);
  else
    addition = false;
  while (quantity > 0)
    {
      if (addition == true)
	pos = next_y(map, pos);
      else
	pos = prev_y(map, pos);
      quantity--;
    }
  return (pos);
}
