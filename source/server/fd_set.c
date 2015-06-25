/*
** fd_set.c for fd_set in /home/plasko_a/programation/epitech/socket/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jul 28 17:09:12 2014 Antoine Plaskowski
** Last update Thu Jun 25 22:21:12 2015 Antoine Plaskowski
*/

#include	<sys/select.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"fd_set.h"
#include	"client.h"

int		fd_set_cpy(fd_set * const dest, fd_set const * const cpy)
{
  int		i;

  if (dest == NULL || cpy == NULL)
    return (1);
  i = 0;
  while (i < FD_SETSIZE)
    {
      if (FD_ISSET(i, cpy))
	FD_SET(i, dest);
      else
	FD_CLR(i, dest);
      i++;
    }
  return (0);
}

int		fd_set_close(fd_set const * const fd_set)
{
  int		i;

  if (fd_set == NULL)
    return (1);
  i = 0;
  while (i < FD_SETSIZE)
    {
      if (FD_ISSET(i, fd_set))
	close(i);
      i++;
    }
  return (0);
}

int		fd_set_client(fd_set * const fd_read, fd_set * const fd_write,
			      t_client *client, int const sfd)
{
  int		fd_max;

  if (fd_read == NULL || fd_write == NULL)
    return (-1);
  fd_max = sfd;
  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  FD_SET(sfd, fd_read);
  client = first_node(&client->node);
  while (client != NULL)
    {
      if (client->ca.cfd > fd_max)
	fd_max = client->ca.cfd;
      if (client->to_write != NULL)
	FD_SET(client->ca.cfd, fd_write);
      FD_SET(client->ca.cfd, fd_read);
      client = client->node.next;
    }
  return (fd_max);
}
