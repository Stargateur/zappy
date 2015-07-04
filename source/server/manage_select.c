/*
** manage_select.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 18:38:07 2015 zwertv_e
** Last update Fri Jul  3 21:39:50 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"client.h"
#include	"manage_select.h"
#include	"fd_set.h"
#include	"int_handler.h"

static t_client	*read_client(fd_set const * const fd_read, t_client *list)
{
  t_client	*client;
  t_client	*client2;

  client = first_node(&list->node);
  while (client != NULL)
    {
      client2 = client->node.next;
      if (FD_ISSET(client->ca.cfd, fd_read))
	{
	  if (write_cbuf(&client->cbuf, client->ca.cfd) <= 0)
	    list = sup_client(client);
	  else
	    if (clock_gettime(CLOCK_MONOTONIC_RAW, &client->time) == -1)
	      {
		perror("clock_gettime :");
		list = sup_client(client);
	      }
	}
      client = client2;
    }
  return (list);
}

static t_client	*write_to_write(t_client *client)
{
  client->to_write = first_node(&client->to_write->node);
  if (client->to_write == NULL)
    return (client);
  if (write_fd(client->to_write->str, client->ca.cfd) == true)
    return (sup_client(client));
  free(client->to_write->str);
  client->to_write = sup_node(&client->to_write->node);
  return (client);
}

static t_client	*write_client(fd_set const * const fd_write, t_client *list)
{
  t_client	*client;
  t_client	*client2;

  client = first_node(&list->node);
  while (client != NULL)
    {
      client2 = client->node.next;
      if (FD_ISSET(client->ca.cfd, fd_write))
	client = write_to_write(client);
      client = client2;
    }
  return (list);
}

t_client	*manage_select(t_client *client, t_time *time, int const sfd)
{
  fd_set	fd_read;
  fd_set	fd_write;
  int		fd_max;

  fd_max = fd_set_client(&fd_read, &fd_write, client, sfd);
  if (pselect(fd_max + 1, &fd_read, &fd_write, NULL, time, NULL) == -1)
    {
      perror("select()");
      g_keep_running = false;
      return (client);
    }
  if (FD_ISSET(sfd, &fd_read) && (client = add_client(client, sfd)) == NULL)
    {
      g_keep_running = false;
      return (client);
    }
  return (write_client(&fd_write, read_client(&fd_read, client)));
}
