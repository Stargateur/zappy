/*
** manage_select.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 18:38:07 2015 zwertv_e
** Last update Fri Jun 19 15:48:11 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	"client.h"
#include	"manage_select.h"
#include	"opt.h"
#include	"fd_set.h"
#include	"int_handler.h"

static t_client	*read_client(fd_set const * const set_read, t_client *client)
{
  t_client	*tmp;

  tmp = first_node(&client->node);
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->ca.cfd, set_read))
	{
	  /* if ((tmp = find_client((*client), client)) != NULL) */
	  /*   if (writeCbuf(tmp->client, &tmp->cbuf) <= 0) */
	  /*     (*client) = sup_node(&tmp->node); */
	}
      tmp = tmp->node.next;
    }
  return (client);
}

static t_client	*write_client(fd_set const * const set_write, t_client *client)
{
  t_client	*tmp;

  tmp = first_node(&client->node);
  while (tmp != NULL)
   {
      if (FD_ISSET(tmp->ca.cfd, set_write))
	{
	  /* exec_client(*client, chans); */
	  /* *client = clean_client(tmp); */
	  /* tmp = *client; */
	}
      if (tmp != NULL)
	tmp = tmp->node.next;
    }
  return (client);
}

static t_client	*manage_accept_client(t_client *client, int const sfd)
{
  t_clientaddr	ca;

  if (accept_client(sfd, &ca) == -1)
    return (NULL);
  return (add_client(client, &ca));
}

bool	manage_select(int const sfd)
{
  fd_set	set_read;
  fd_set	set_write;
  int		client_max;
  t_client	*client;

  client = NULL;
  while (g_keep_running == true)
    {
      client_max = fd_set_rclient(&set_read, client, sfd);
      fd_set_wclient(&set_write, client);
      if (select(client_max + 1, &set_read, &set_write, NULL, NULL) == -1)
	{
	  perror("select()");
	  return (true);
	}
      if (FD_ISSET(sfd, &set_read))
	if ((client = manage_accept_client(client, sfd)) == NULL)
	  return (true);
      read_client(&set_read, client);
      write_client(&set_write, client);
    }
  return (false);
}
