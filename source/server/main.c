/*
** main.c for main in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Tue Jun 16 16:38:42 2015 Antoine Plaskowski
** Last update Thu Jun 18 18:07:15 2015 Antoine Plaskowski
*/

#include        <unistd.h>
#include        <signal.h>
#include        <stdio.h>
#include	<sys/socket.h>
#include	"parse_opt.h"
#include	"create_binded_socket.h"

bool    g_keep_running = true;

static void     int_handler(int const signum)
{
  (void)signum;
  g_keep_running = false;
}

static int	init_socket(char const * const port)
{
  int		sfd;

  if (signal(SIGINT, int_handler) == SIG_ERR)
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
  t_opt		opt;

  parse_opt(argv, argc, &opt);
  show_opt(&opt);
  if ((sfd = init_socket(opt.p)) == -1)
    return (1);
  close(sfd);
  return (0);
}
