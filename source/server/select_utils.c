/*
** select_utils.c for select_utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jul  2 18:28:45 2015 Antoine Plaskowski
** Last update Thu Jul  2 18:55:07 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	"player.h"
#include	"utils.h"

t_time          *set_shortest_time(t_player *player, t_time *select_time)
{
  t_time	actual_time;

  if (clock_gettime(CLOCK_MONOTONIC, &actual_time) == -1)
    {
      perror("clock_gettime :");
      return (true);
    }
  player = first_node(&player->node);
  while (player != NULL)
    {
      player->action = first_node(&player->action->node);
      if (player->action != NULL)
	if (time_small(&player->act, time) == true)
	  player = player->node.next;
    }
}
