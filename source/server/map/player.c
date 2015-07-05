/*
** player.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:20:46 2015 zwertv_e
** Last update Sun Jul  5 17:08:16 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"player.h"

void		rotate_left(t_player * const player)
{
  if (player != NULL)
    {
      switch (player->dir)
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
      switch (player->dir)
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
      switch (player->dir)
	{
	case NORTH:
	  player->coord.y = next_y(map, player->coord.y);
	  break;
	case SOUTH:
	  player->coord.y = prev_y(map, player->coord.y);
	  break;
	case WEST:
	  player->coord.x = prev_x(map, player->coord.x);
	  break;
	case EAST:
	  player->coord.x = next_x(map, player->coord.x);
	  break;
	};
    }
}

t_player		*init_player(t_map *map, t_team * const team,
				     size_t const x, size_t const y)
{
  t_player		*player;

  if (team == NULL || map == NULL)
    return (NULL);
  if (map->width == 0 || map->height == 0)
    return (NULL);
  if ((player = malloc(sizeof(*player))) == NULL)
    return (NULL);
  player->coord.x = x % map->width;
  player->coord.y = y % map->height;
  player->dir = random() % (EAST + 1);
  player->range = 1;
  if (clock_gettime(CLOCK_MONOTONIC_RAW, &player->food) == -1)
    {
      perror("clock_gettime :");
      free(player);
      return (NULL);
    }
  player->client = NULL;
  player->action = NULL;
  init_inv(&player->inv);
  add_ressource(&player->inv, FOOD, 10, true);
  player->team = team;
  return (player);
}
