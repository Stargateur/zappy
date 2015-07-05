/*
** kill_client.c for kill_client in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jul  2 17:04:08 2015 Antoine Plaskowski
** Last update Sun Jul  5 05:26:31 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"kill_client.h"
#include	"client.h"
#include	"game.h"

static bool	kill_timeout(t_time *client, t_time const *timeout, t_time act)
{
  if (time_sub(&act, client) == true)
    return (true);
  if (time_small(&act, timeout) == false)
    return (true);
  return (false);
}

t_client	*kill_client(t_client *list)
{
  t_time	timeout;
  t_client	*client;
  t_client	*client2;
  t_time	act;

  if (clock_gettime(CLOCK_MONOTONIC_RAW, &act) == -1)
    {
      perror("clock_gettime :");
      return (NULL);
    }
  timeout.tv_sec = 5;
  timeout.tv_nsec = 0;
  client = first_node(&list->node);
  while (client != NULL)
    {
      client2 = client->node.next;
      if (client->to_kill == true && client->to_write == NULL)
	list = sup_client(client);
      else if (client->player == NULL)
	if (kill_timeout(&client->time, &timeout, act) == true)
	  list = sup_client(client);
      client = client2;
    }
  return (list);
}
