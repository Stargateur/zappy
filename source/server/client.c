/*
** client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:00 2015 zwertv_e
** Last update Thu Jul  2 17:04:39 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"client.h"
#include	"game.h"

t_string	*add_string(t_string * const list, char *str)
{
  t_string	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->str = strdup(str);
  return (put_node(&list->node, &new->node));
}

t_client	*add_client(t_client * const list, int const sfd)
{
  t_client	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  if (clock_gettime(CLOCK_MONOTONIC, &new->time) == -1)
    {
      free(new);
      perror("clock_gettime : ");
      return (NULL);
    }
  if (accept_client(sfd, &new->ca) == -1)
    {
      free(new);
      return (NULL);
    }
  new->to_write = add_string(NULL, "BIENVENUE\n");
  new->player = NULL;
  new->to_kill = false;
  init_cbuf(&new->cbuf);
  return (put_node(&list->node, &new->node));
}

bool		write_pos_player(t_client * const client)
{
  char		*str;
  int		len;

  if (client == NULL || client->player == NULL)
    return (true);
  len = snprintf(NULL, 0, "%lu %lu\n", client->player->coords.x,
		 client->player->coords.y);
  if (len < 0)
    return (true);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (true);
  if (snprintf(str, (size_t)len + 1, "%lu %lu\n",
	       client->player->coords.x, client->player->coords.y) != len)
    return (true);
  client->to_write = add_string(client->to_write, str);
  free(str);
  return (false);
}

t_client	*sup_client(t_client *client)
{
  if (client == NULL)
    return (NULL);
  if (client->player != NULL)
    client->player->client = NULL;
  close(client->ca.cfd);
  while (client->to_write != NULL)
    {
      free(client->to_write->str);
      client->to_write = sup_node(&client->to_write->node);
    }
  return (sup_node(&client->node));
}
