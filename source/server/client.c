/*
** client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:00 2015 zwertv_e
** Last update Wed Jul  1 06:19:11 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
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
  if (accept_client(sfd, &new->ca) == -1)
    {
      free(new);
      return (NULL);
    }
  new->to_write = add_string(NULL, "BIENVENUE\n");
  new->player = NULL;
  init_cbuf(&new->cbuf);
  return (put_node(&list->node, &new->node));
}

bool		write_pos_player(t_client * const client)
{
  char		*str;
  int		len;

  if (client == NULL || client->player == NULL)
    return (true);
  len = snprintf(NULL, 0, "%lu %lu\n", client->player->x, client->player->y);
  if (len < 0)
    return (true);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (true);
  if (snprintf(str, (size_t)len + 1, "%lu %lu\n",
	       client->player->x, client->player->y) != len)
    return (true);
  client->to_write = add_string(client->to_write, str);
  free(str);
  return (false);
}
