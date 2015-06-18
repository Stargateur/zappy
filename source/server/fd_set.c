/*
** fd_set.c for fd_set in /home/plasko_a/programation/epitech/socket/source
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jul 28 17:09:12 2014 Antoine Plaskowski
** Last update Thu Jun 18 22:54:39 2015 Antoine Plaskowski
*/

/* #include	<sys/time.h> */
/* #include	<sys/types.h> */
/* #include	<unistd.h> */
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

bool		fd_set_wclient(fd_set *fdset, t_client *client)
{
  if (fdset == NULL)
    return (false);
  FD_ZERO(fdset);
  client = first_node(&client->node);
  while (client != NULL)
    {
      /* FD_SET(client->ca.cfd, fdset); */
      client = client->node.next;
    }
  return (true);
}

int		fd_set_rclient(fd_set *fdset, t_client *client, int sfd)
{
  int		max_fd;

  if (fdset == NULL)
    return (-1);
  max_fd = sfd;
  FD_ZERO(fdset);
  FD_SET(sfd, fdset);
  client = first_node(&client->node);
  while (client != NULL)
    {
      if (client->ca.cfd > max_fd)
	max_fd = client->ca.cfd;
      FD_SET(client->ca.cfd, fdset);
      client = client->node.next;
    }
  return (max_fd);
}
