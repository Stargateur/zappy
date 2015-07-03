/*
** select_utils.c for select_utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jul  2 18:28:45 2015 Antoine Plaskowski
** Last update Fri Jul  3 20:59:34 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	"player.h"
#include	"utils.h"

static bool	truc(t_player *player, t_time cpy_time, t_time *s_time)
{
  if (time_sub(&cpy_time, &player->act) == true)
    return (true);
  
  if (time_small(&player->act, &cpy_time) == true)
    ;
}

t_time          *set_s_time(t_game *game, t_player *player, t_time *s_time)
{
  t_time	actual_time;

  s_time->tv_sec = 1;
  s_time->tv_nsec = 0;
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
	  truc(player, actual_time, s_time);
	}
      player = player->node.next;
    }
}
