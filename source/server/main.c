/*
** main.c for main in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Tue Jun 16 16:38:42 2015 Antoine Plaskowski
** Last update Fri Jun 19 16:16:07 2015 Antoine Plaskowski
*/

#include        <unistd.h>
#include        <signal.h>
#include        <stdio.h>
#include	<sys/socket.h>
#include	"opt.h"
#include	"create_binded_socket.h"
#include	"manage_select.h"
#include	"opt.h"
#include	"int_handler.h"

static int	init_socket(char const * const port)
{
  int		sfd;

  if (signal(SIGINT, &int_handler) == SIG_ERR)
    perror("signal()");
  if ((sfd = create_binded_socket(port)) == -1)
    return (-1);
  if (listen(sfd, 42))
    {
      perror("listen()");
      return (-1);
    }
  return (sfd);
}

int		main(int argc, char **argv)
{
  int		sfd;

  if (get_opt(argv, argc) == true)
    return (1);
  show_opt();
  if ((sfd = init_socket(opt.p)) == -1)
    return (1);
  manage_select(sfd);
  close(sfd);
  return (0);
}
