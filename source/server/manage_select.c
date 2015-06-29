/*
** manage_select.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Sun Apr 26 18:38:07 2015 zwertv_e
** Last update Mon Jun 29 16:18:31 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"client.h"
#include	"manage_select.h"
#include	"opt.h"
#include	"fd_set.h"
#include	"int_handler.h"

static t_client	*read_client(fd_set const * const fd_read, t_client *client)
{
  t_client	*tmp;
  t_client	*tmp2;

  tmp = first_node(&client->node);
  while (tmp != NULL)
    {
      tmp2 = tmp->node.next;
      if (FD_ISSET(tmp->ca.cfd, fd_read))
	if (write_cbuf(&tmp->cbuf, tmp->ca.cfd) <= 0)
	  client = sup_node(&tmp->node);
      tmp = tmp2;
    }
  return (client);
}

static t_string	*write_to_write(t_string *to_write, int const cfd)
{
  to_write = first_node(&to_write->node);
  if (to_write == NULL)
    return (NULL);
  if (to_write->str != NULL)
    write(cfd, to_write->str, strlen(to_write->str));
  return (sup_node(&to_write->node));
}

static t_client	*write_client(fd_set const * const fd_write, t_client *client)
{
  t_client	*tmp;
  t_client	*tmp2;

  tmp = first_node(&client->node);
  while (tmp != NULL)
   {
     tmp2 = tmp->node.next;
     if (FD_ISSET(tmp->ca.cfd, fd_write))
       tmp->to_write = write_to_write(tmp->to_write, tmp->ca.cfd);
     tmp = tmp2;
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

static void	get_cmd(t_client *client)
{
  char		*str;

  client = first_node(&client->node);
  while (client != NULL)
    {
      if (ready_cbuf(&client->cbuf) == true)
	{
	  str = read_cbuf(&client->cbuf);
	  if (str == NULL)
	    return;
	}
      client = client->node.next;
    }
}

bool		manage_select(int const sfd)
{
  fd_set	fd_read;
  fd_set	fd_write;
  int		fd_max;
  t_client	*client;

  client = NULL;
  while (g_keep_running == true)
    {
      fd_max = fd_set_client(&fd_read, &fd_write, client, sfd);
      if (select(fd_max + 1, &fd_read, &fd_write, NULL, NULL) == -1)
	{
	  perror("select()");
	  return (true);
	}
      if (FD_ISSET(sfd, &fd_read))
	if ((client = manage_accept_client(client, sfd)) == NULL)
	  return (true);
      client = read_client(&fd_read, client);
      client = write_client(&fd_write, client);
      get_cmd(client);
    }
  return (false);
}
