/*
** main.c for main in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Tue Jun 16 16:38:42 2015 Antoine Plaskowski
** Last update Thu Jun 25 22:51:09 2015 zwertv_e
*/

#include        <unistd.h>
#include        <signal.h>
#include        <stdio.h>
#include	<sys/socket.h>
#include        <SDL2/SDL.h>
#include        "graphic.h"
#include	"opt.h"
#include	"create_binded_socket.h"
#include	"manage_select.h"
#include	"opt.h"
#include	"int_handler.h"
#include	"map.h"
#include	"node.h"
#include	"player.h"
#include	"inv.h"

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
  t_texture     text;
  SDL_Renderer  *renderer;
  SDL_Window    *fenetre;

  t_map			map;
  t_squarre		*disp;

  fenetre = init_video();
  renderer = init_renderer(fenetre);
  init_texture(&text, renderer);

  init_map(&map, 50, 50);
  map_generate(&map);
  disp = first_node(&map.items->node);
  while (disp != NULL)
    {
      printf("[%lu - %lu] %lu %lu %lu %lu %lu %lu %lu\n", disp->x, disp->y, disp->ressources.linemlate, disp->ressources.deraumere, disp->ressources.sibur, disp->ressources.mendiane, disp->ressources.phiras, disp->ressources.thystame, disp->ressources.food);
      disp = disp->node.next;
    }

  draw_stone(&map, &text, renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  draw_grid(renderer, &map);
  SDL_RenderPresent(renderer);

  sleep(5);
  t_player		test;

  init_player(&test, 0, 0, "Razmoket");
  test.inv.linemlate += 2;
  test.inv.food += 5;
  printf("Inventory: %s\n", get_inventory(&test.inv));
  move(&map, &test);
  rotate_left(&test);
  move(&map, &test);
  rotate_left(&test);
  move(&map, &test);
  rotate_right(&test);
  rotate_right(&test);
  rotate_right(&test);
  move(&map, &test);
  rotate_left(&test);
  if (test.dir == NORTH)
    printf("Player has rotated correctly\n");

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
