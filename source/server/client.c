/*
** client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:00 2015 zwertv_e
** Last update Sun Jul  5 02:19:25 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"client.h"
#include	"game.h"

bool		add_string(t_client *client, char *str)
{
  t_string	*new;

  if (client == NULL || str == NULL)
    return (true);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (true);
  new->str = strdup(str);
  client->to_write = put_node(&client->to_write->node, &new->node);
  return (false);
}

t_client	*add_client(t_client * const list, int const sfd)
{
  t_client	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  if (clock_gettime(CLOCK_MONOTONIC_RAW, &new->time) == -1)
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
  new->to_write = NULL;
  add_string(new, "BIENVENUE\n");
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
  len = snprintf(NULL, 0, "%lu %lu\n", client->player->coord.x,
		 client->player->coord.y);
  if (len < 0)
    return (true);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (true);
  if (snprintf(str, (size_t)len + 1, "%lu %lu\n",
	       client->player->coord.x, client->player->coord.y) != len)
    return (true);
  add_string(client, str);
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
