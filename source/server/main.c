/*
** main.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Mon Jun 29 22:47:01 2015 zwertv_e
<<<<<<< HEAD
** Last update Thu Jul  2 15:49:06 2015 Alaric
=======
** Last update Thu Jul  2 15:46:10 2015 Antoine Plaskowski
>>>>>>> ae0c01b9c8aee2651d8a0ae39ddae0debcee4b10
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

void		plasko(int argc, char **argv)
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
  srandom((unsigned int)time(NULL));
  if (init_game(&game, argv, argc) == NULL)
    return (1);
  show_option(&game.option);
  if ((sfd = init_socket(game.option.p)) == -1)
    return (1);
  while (g_keep_running == true)
    {
      client = manage_select(client, sfd);
      get_cmd(&game, client);
    }
  close(sfd);
}

void		costa_alaric()
{
  /*
  **
  ** TEST UNITAIRE COSTA + ALARIC
  **
  */
  t_game	game;
  t_texture     text;
  t_display	*display;
  SDL_Window    *fenetre;
  t_map			map;
  t_square		*disp;

  if ((display = malloc(sizeof(t_display))) == NULL)
    return (1);
  fenetre = init_video();
  display = init_renderer(fenetre, display);
  init_texture(&text, display->renderer);

  init_map(&map, 50, 50);
  map_generate(&map);
  disp = first_node(&map.items->node);
  while (disp != NULL)
    {
      printf("[%lu - %lu] %lu %lu %lu %lu %lu %lu %lu\n", disp->coords.x, disp->coords.y, disp->ressources.linemate, disp->ressources.deraumere, disp->ressources.sibur, disp->ressources.mendiane, disp->ressources.phiras, disp->ressources.thystame, disp->ressources.food);
      disp = disp->node.next;
    }

  int cont = 0;

  while (cont == 0)
    {
      cont = input(display, &map);
      draw_stone(&map, &text, display);
      draw_grid(&map, display);
      draw_select(display);
      SDL_RenderPresent(display->renderer);
      SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255);
      SDL_RenderClear(display->renderer);
      SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255);
    }

  /* draw_stone(&map, &text, renderer, display); */
  SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255);
  draw_grid(&map, display);
  draw_select(display);
  SDL_RenderPresent(display->renderer);

  sleep(5);
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

  init_game(&party_everyday, argv, argc);
  init_map(&mapr, 50, 50);
  map_generate(&mapr);
  test = init_player(&mapr, "Razmoket", 49, 49);
  party_everyday.player = put_node(party_everyday.player, test);
  test = init_player(&mapr, "Razmoket", 0, 0);
  party_everyday.player = put_node(party_everyday.player, test);
  printf("player is in %lu - %lu\n", test->coords.x, test->coords.y);
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

  player_view(&party_everyday, &mapr, test);
  add_item(&mapr, 0, 0, LINEMATE);
  player_view(&party_everyday, &mapr, test);
  player_levelup(&party_everyday, &mapr, test, true);
  if (test->range == 2)
    printf("Player successfuly elevated !\n");
  player_view(&party_everyday, &mapr, test);
}

int		main(int argc, char **argv)
{
  /* plasko(argc, argv); */
   costa_alaric();
  /* elliott(argc, argv); */
  return (0);
}
