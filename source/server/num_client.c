/*
** num_client.c for num_client in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 05:36:20 2015 Antoine Plaskowski
** Last update Wed Jul  1 05:50:30 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	<stdio.h>
#include	<stddef.h>
#include	"client.h"

bool		write_num_client(t_client * const client, size_t const num_client)
{
  char		*str;
  int		len;

  if (client == NULL)
    return (true);
  if ((len = snprintf(NULL, 0, "%lu\n", num_client)) < 0)
    return (true);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (true);
  if (snprintf(str, (size_t)len + 1, "%lu\n", num_client) != len)
    return (true);
  client->to_write = add_string(client->to_write, str);
  free(str);
  return (false);
}

