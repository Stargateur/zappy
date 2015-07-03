/*
** select_utils.c for select_utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jul  2 18:28:45 2015 Antoine Plaskowski
** Last update Fri Jul  3 20:40:03 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	"player.h"
#include	"utils.h"

t_time          *set_shortest_time(t_player *player, t_time *select_time)
{
  t_time	actual_time;
  t_time	cpy;

  select_time->tv_sec = 1;
  select_time->tv_nsec = 0;
  if (clock_gettime(CLOCK_MONOTONIC, &actual_time) == -1)
    {
      perror("clock_gettime :");
      return (NULL);
    }
  player = first_node(&player->node);
  while (player != NULL)
    {
      player->action = first_node(&player->action->node);
      if (player->action != NULL)
	{
	  cpy = actual_time;
	  time_sub(&cpy, &player->act);
	  
	  if (time_small(&player->act, &cpy) == true)
	    ;
	}
      player = player->node.next;
    }
}
