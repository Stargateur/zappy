/*
** main.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jul  2 19:00:16 2015 zwertv_e
** Last update Fri Jul  3 16:15:06 2015 Antoine Plaskowski
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

int		plasko(int argc, char **argv)
{
  /*
  **
  ** TEST UNITAIRE PLASKO
  **
  */
  int		sfd;
  t_client	*client;
  t_game	game;

  client = NULL;
  if (init_game(&game, argv, argc) == NULL)
    return (1);
  show_option(&game.option);
  if ((sfd = init_socket(game.option.p)) == -1)
    return (1);
  while (g_keep_running == true)
    {
      client = manage_select(client, sfd);
      get_cmd(&game, client);
      client = kill_client(client);
    }
  while (client != NULL)
    client = sup_client(client);
  printf("Bye mother fucker\n");
  close(sfd);
  return (0);
}

int		costa_alaric(void)
{
  /*
  **
  ** TEST UNITAIRE COSTA + ALARIC
  **
  */
  t_texture     text;
  t_display	*display;
  SDL_Window    *fenetre;
  t_map			map;
  t_square		*disp;
  int cont = 0;

  if ((display = malloc(sizeof(t_display))) == NULL)
    return (1);
  fenetre = init_video();
  display = init_renderer(fenetre, display);
  init_texture(&text, display->renderer);

  init_map(&map, 100, 100);
  map_generate(&map);
  disp = first_node(&map.items->node);
  while (disp != NULL)
    {
      printf("[%lu - %lu] %lu %lu %lu %lu %lu %lu %lu\n", disp->coord.x, disp->coord.y, disp->ressources.linemate, disp->ressources.deraumere, disp->ressources.sibur, disp->ressources.mendiane, disp->ressources.phiras, disp->ressources.thystame, disp->ressources.food);
      disp = disp->node.next;
    }


  while (cont == 0)
    {
      cont = input(display, &map);
      draw_stone(&map, &text, display);
      draw_grid(&map, display);
      draw_select(display, &map, &text);
      SDL_RenderPresent(display->renderer);
      SDL_SetRenderDrawColor(display->renderer, 0, 127, 0, 255);
      SDL_RenderClear(display->renderer);
      SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255);
    }

  /* draw_stone(&map, &text, renderer, display); */
  SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255);
  draw_grid(&map, display);
  draw_select(display, &map, &text);
  SDL_RenderPresent(display->renderer);

  sleep(5);
  return (0);
}

void		elliott(int argc, char **argv)
{
/*
  **
  ** TEST UNITAIRE ELLIOTT
  **
  */
  t_game		party_everyday;
  t_map			mapr;
  t_player		*test;
  char			*inv;
  char			*view;

  init_game(&party_everyday, argv, argc);
  init_map(&mapr, 50, 50);
  map_generate(&mapr);
  test = init_player(&mapr, "Razmoket", 49, 49);
  party_everyday.player = put_node(&party_everyday.player->node, &test->node);
  test = init_player(&mapr, "Razmoket", 0, 0);
  party_everyday.player = put_node(&party_everyday.player->node, &test->node);
  printf("player is in %lu - %lu\n", test->coord.x, test->coord.y);
  init_inv(&test->inv);
  test->inv.linemate += 2;
  test->inv.food += 5;
  inv = get_inventory(&test->inv);
  if (inv)
    {
      printf("Inventory: %s\n", inv);
      free(inv);
    }
  else
    printf("Inv is NULL\n");

  view = player_view(&party_everyday, &mapr, test);
  if (view)
    {
      printf("View: %s\n", view);
      free(view);
    }
  else
    printf("View is NULL\n");

  move(&mapr, test);
  rotate_left(test);
  move(&mapr, test);
  rotate_left(test);
  move(&mapr, test);
  rotate_right(test);
  rotate_right(test);
  rotate_right(test);
  move(&mapr, test);
  rotate_left(test);
  if (test->dir == NORTH)
    printf("Player has rotated correctly\n");

  view = player_view(&party_everyday, &mapr, test);
  if (view)
    {
      printf("View: %s\n", view);
      free(view);
    }
  else
    printf("View is NULL\n");
  add_item(&mapr, 0, 0, LINEMATE);
  view = player_view(&party_everyday, &mapr, test);
  if (view)
    {
      printf("View: %s\n", view);
      free(view);
    }
  else
    printf("View is NULL\n");
  player_levelup(&party_everyday, &mapr, test, true);
  if (test->range == 2)
    printf("Player successfuly elevated !\n");
  view = player_view(&party_everyday, &mapr, test);
  if (view)
    {
      printf("View: %s\n", view);
      free(view);
    }
  else
    printf("View is NULL\n");
}

int		main(int argc, char **argv)
{
  srandom((unsigned int)time(NULL));
  plasko(argc, argv);
  costa_alaric();
  /* elliott(argc, argv); */
  return (0);
}
