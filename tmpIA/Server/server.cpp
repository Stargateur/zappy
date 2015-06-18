/*
** etape_1.c for etape in /home/xila/home/unix/my_ftp/tp
** 
** Made by Amoureux Alix
** Login   <xila@epitech.net>
** 
** Started on  Tue Apr  8 11:49:10 2014 Amoureux Alix
// Last update Mon Jun 15 12:57:54 2015 amoure_a
*/

#include		"infos.h"

static int		read_input(int cs, t_infos *infos)
{
  char			*buffer;
  int			quit;
  int			end;

  quit = 0;
  while (quit == 0)
    {
      
    }
  if (infos->user)
    printf("Client \x1B[31m%s \x1B[0mhas left conversation\n", infos->user);
  else
    printf("Client \x1B[31mAnonymous \x1B[0mhas left conversation\n");
  return (1);
}

static int		execution(int *fd, struct sockaddr_in sin_client,
				  t_infos *infos)
{
  int			client;

  fd[2] = sizeof(sin_client);
  if ((fd[1] = accept(fd[0], (struct sockaddr *)&sin_client,
		      (socklen_t *)&fd[2])) == -1)
    std::cerr << "Error on accept" << std::endl;
  if ((client = fork()) == -1)
    std::cerr << "Error on fork" << std::endl;
  else if (client == 0)
    {
      printf("client \x1B[31mAnonymous \x1B[0mhas connected\n");
      write(fd[1], "220 Service ready for new user.\r\n",
	     strlen("220 Service ready for new user.\r\n"));
      read_input(fd[1], infos);
      write(fd[1], "221 Service closing control connection.\r\n",
	     strlen("221 Service closing control connection.\r\n"));
      close(fd[1]);
    }
  return (1);
}

int			main(int ac, char **av)
{
  int			fd[3];
  struct sockaddr_in	sin_client;
  t_infos		*infos;

  if (ac != 2)
    std::cerr << "Error on arguments" << std::endl;
  if ((fd[0] = init(atoi(av[1]))) == -1)
    return (-1);
  while (1)
    execution(fd, sin_client, infos);
  close(fd[0]);
  return (0);
}
