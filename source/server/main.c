/*
** main.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Jul  3 16:46:24 2015 zwertv_e
** Last update Sat Jul  4 21:33:30 2015 Antoine Plaskowski
*/

#include        <unistd.h>
#include        <signal.h>
#include        <stdio.h>
#include	<sys/socket.h>
#include        <SDL2/SDL.h>
#include	<pthread.h>
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
#include	"kill_client.h"

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

static void	*graphic(t_game *game)
{
  t_texture	texture;
  t_display	display;

  display.fenetre = init_video();
  init_renderer(display.fenetre, &display);
  init_texture(&texture, display.renderer);
  while (g_keep_running == true)
    {
      SDL_WaitEvent(NULL);
      pthread_mutex_lock(&game->mutex);
      input(&display, &game->map);
      draw_stone(&game->map, &texture, &display);
      draw_grid(&game->map, &display);
      draw_select(&display, &game->map, &texture);
      SDL_RenderPresent(display.renderer);
      SDL_SetRenderDrawColor(display.renderer, 0, 127, 0, 255);
      SDL_RenderClear(display.renderer);
      SDL_SetRenderDrawColor(display.renderer, 255, 255, 255, 255);
      pthread_mutex_unlock(&game->mutex);
    }
  return (game);
}

static t_client	*game_select(t_game *game, t_client *client, int sfd)
{
  if (do_action(game) == true)
    client = manage_select(client, NULL, sfd);
  else
    client = manage_select(client, &game->s_time, sfd);
  pthread_mutex_lock(&game->mutex);
  get_cmd(game, client);
  client = kill_client(client);
  pthread_mutex_unlock(&game->mutex);
  return (client);
}

int		main(int argc, char **argv)
{
  pthread_t	pthread;
  int		sfd;
  t_client	*client;
  t_game	game;

  srandom((unsigned int)time(NULL));
  client = NULL;
  if (init_game(&game, argv, argc) == NULL)
    return (1);
  show_option(&game.option);
  if (pthread_create(&pthread, NULL, (void *(*)(void *))&graphic, &game) != 0)
    return (false);
  if ((sfd = init_socket(game.option.p)) == -1)
    return (1);
  while (g_keep_running == true)
    client = game_select(&game, client, sfd);
  if (pthread_join(pthread, NULL) != 0)
    return (false);
  while (client != NULL)
    client = sup_client(client);
  printf("Bye\n");
  close(sfd);
  delete_game(&game);
  return (0);
}
