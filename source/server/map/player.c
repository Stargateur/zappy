/*
** player.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:20:46 2015 zwertv_e
** Last update Thu Jun 25 22:22:44 2015 zwertv_e
*/

#include	<string.h>
#include	"player.h"

void		rotate_left(t_player * const player)
{
  if (player != NULL)
    {
      switch(player->dir)
	{
	case NORTH:
	  player->dir = WEST;
	  break;
	case SOUTH:
	  player->dir = EAST;
	  break;
	case WEST:
	  player->dir = SOUTH;
	  break;
	case EAST:
	  player->dir = NORTH;
	  break;
	};
    }
}

void		rotate_right(t_player * const player)
{
  if (player != NULL)
    {
      switch(player->dir)
	{
	case NORTH:
	  player->dir = EAST;
	  break;
	case SOUTH:
	  player->dir = WEST;
	  break;
	case WEST:
	  player->dir = NORTH;
	  break;
	case EAST:
	  player->dir = SOUTH;
	  break;
	};
    }
}

void		move(t_map const * const map, t_player * const player)
{
  if (player != NULL)
    {
      if (player->y == 0)
	player->y += map->height;
      if (player->x == 0)
	player->x += map->width;
      switch(player->dir)
	{
	case NORTH:
	  player->y--;
	  break;
	case SOUTH:
	  player->y++;
	  break;
	case WEST:
	  player->x--;
	  break;
	case EAST:
	  player->x++;
	  break;
	};
      player->y = player->y % map->height;
      player->x = player->x % map->width;
      printf("Player has moved in [%lu - %lu]\n", player->x, player->y);
    }
}

void		init_player(t_player * const player, size_t const x,
				    size_t const y, char const * const team)
{
  player->x = x;
  player->y = y;
  player->dir = NORTH;
  player->team = NULL;
  init_inv(&player->inv);
  if (team != NULL)
    player->team = strdup(team);
  printf("New player at pos [%lu - %lu] in '%s' team\n", player->x, player->y, player->team);
}
