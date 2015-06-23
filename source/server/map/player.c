/*
** player.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:20:46 2015 zwertv_e
** Last update Tue Jun 23 14:54:28 2015 zwertv_e
*/

#include		<string.h>
#include		"player.h"

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
