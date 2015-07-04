/*
** action.c for action in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 18:18:56 2015 Antoine Plaskowski
** Last update Sat Jul  4 14:55:31 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	"player.h"
#include	"utils.h"
#include	"action.h"

bool		show_action(t_action *action)
{
  printf("Les actions sont :\n");
  action = first_node(&action->node);
  while (action != NULL)
    {
      printf("%s\n", action->str);
      action = action->node.next;
    }
  return (false);
}

static bool	truc(t_player *player, t_time cpy_time, t_time *s_time)
{
  if (time_sub(&cpy_time, &player->act) == true)
    return (true);
  while (time_small(&player->action->time, &cpy_time) == true)
    {
      exec_action();
      time_add(&player->act, &player->action->time);
      time_add(&player->act, &player->action->time);
    }

  return (false);
}

bool		do_action(t_player *player, t_time *s_time)
{
  t_time	actual_time;

  time_div(s_time, 1, 60);
  return (false);
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
	{
	  truc(player, actual_time, s_time);
	}
      player = player->node.next;
    }
  return (false);  
}
