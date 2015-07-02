/*
** main.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Mon Jun 29 22:47:01 2015 zwertv_e
** Last update Thu Jul  2 14:41:31 2015 Antoine Plaskowski
*/

#include        <unistd.h>
#include        <signal.h>
#include        <stdio.h>
#include	<sys/socket.h>
#include        <SDL2/SDL.h>
#include        "graphic.h"
#include	"create_binded_socket.h"
#include	"manage_select.h"
#include	"int_handler.h"
#include	"game.h"
#include	"map.h"
#include	"node.h"
#include	"player.h"
#include	"inv.h"
#include	"command.h"

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
  t_game	game;
  int		sfd;
  t_client	*client;

  client = NULL;
  srandom((unsigned int)time(NULL));
  if (init_game(&game, argv, argc) == NULL)
    return (1);
  show_option(&game.option);
  if ((sfd = init_socket(game.option.p)) == -1)
    return (1);
  while (g_keep_running == true)
    {
      client = manage_select(client, sfd);
      client = get_cmd(&game, client);
    }
  close(sfd);
  return (0);
}
