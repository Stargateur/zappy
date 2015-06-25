/*
** main.c for main in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Tue Jun 16 16:38:42 2015 Antoine Plaskowski
** Last update Thu Jun 25 15:41:50 2015 zwertv_e
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
#include	"map.h"
#include	"node.h"

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
  t_map			map;
  t_squarre		*disp;

  init_map(&map, 20, 20);
  while (map_generate(&map));
  disp = first_node(&map.items->node);
  while (disp != NULL)
    {
      printf("[%zu - %zu] %zu %zu %zu %zu %zu %zu %zu\n", disp->x, disp->y, disp->ressources.linemlate, disp->ressources.deraumere, disp->ressources.sibur, disp->ressources.mendiane, disp->ressources.phiras, disp->ressources.thystame, disp->ressources.food);
      disp = disp->node.next;
    }
  /* int		sfd; */

  /* if (get_opt(argv, argc) == true) */
  /*   return (1); */
  /* show_opt(); */
  /* if ((sfd = init_socket(opt.p)) == -1) */
  /*   return (1); */
  /* manage_select(sfd); */
  /* close(sfd); */
  /* return (0); */
}
