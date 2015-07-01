/*
** main.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Mon Jun 29 22:47:01 2015 zwertv_e
** Last update Wed Jul  1 06:02:23 2015 Antoine Plaskowski
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
  /* t_texture     text; */
  /* t_display	*display; */
  /* SDL_Window    *fenetre; */
  /* t_map			map; */
  /* t_squarre		*disp; */

  /* if ((display = malloc(sizeof(t_display))) == NULL) */
  /*   return (1); */
  /* fenetre = init_video(); */
  /* display = init_renderer(fenetre, display); */
  /* init_texture(&text, display->renderer); */

  /* init_map(&map, 50, 50); */
  /* map_generate(&map); */
  /* disp = first_node(&map.items->node); */
  /* while (disp != NULL) */
  /*   { */
  /*     printf("[%lu - %lu] %lu %lu %lu %lu %lu %lu %lu\n", disp->x, disp->y, disp->ressources.linemlate, disp->ressources.deraumere, disp->ressources.sibur, disp->ressources.mendiane, disp->ressources.phiras, disp->ressources.thystame, disp->ressources.food); */
  /*     disp = disp->node.next; */
  /*   } */

  /* int cont = 0; */

  /* while (cont == 0) */
  /*   { */
  /*     cont = input(display); */
  /*     draw_stone(&map, &text, display); */
  /*     draw_grid(&map, display); */
  /*     draw_select(display); */
  /*     SDL_RenderPresent(display->renderer); */
  /*     SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255); */
  /*     SDL_RenderClear(display->renderer); */
  /*     SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255); */
  /*   } */

  /* /\* draw_stone(&map, &text, renderer, display); *\/ */
  /* SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255); */
  /* draw_grid(&map, display); */
  /* draw_select(display); */
  /* SDL_RenderPresent(display->renderer); */

  /* sleep(5); */
  /* t_map			map; */
  /* t_player		test; */
  /* char			*inv; */
  /* char			*view; */

  /* init_map(&map, 50, 50); */
  /* map_generate(&map); */
  /* init_player(&test, 0, 0, "Razmoket"); */
  /* test.inv.linemlate += 2; */
  /* test.inv.food += 5; */
  /* inv = get_inventory(&test.inv); */
  /* if (inv) */
  /*   { */
  /*     printf("Inventory: %s\n", inv); */
  /*     free(inv); */
  /*   } */
  /* else */
  /*   printf("Inv is NULL\n"); */
  /* move(&map, &test); */
  /* rotate_left(&test); */
  /* move(&map, &test); */
  /* rotate_left(&test); */
  /* move(&map, &test); */
  /* rotate_right(&test); */
  /* rotate_right(&test); */
  /* rotate_right(&test); */
  /* move(&map, &test); */
  /* rotate_left(&test); */
  /* if (test.dir == NORTH) */
  /*   printf("Player has rotated correctly\n"); */

  /* view = player_view(&map, &test); */
  /* if (view) */
  /*   { */
  /*     printf("View: %s\n", view); */
  /*     free(view); */
  /*   } */
  /* else */
  /*   printf("View is NULL\n"); */

  client = NULL;
  srandom((unsigned int)time(NULL));
  if (init_game(&game, argv, argc) == NULL)
    return (1);
  show_option(&game.option);
  if ((sfd = init_socket(game.option.p)) == -1)
    return (1);
  while (g_keep_running == true)
    client = manage_select(client, sfd);
  close(sfd);
  return (0);
}
