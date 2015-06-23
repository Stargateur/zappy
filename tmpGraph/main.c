/*
** main.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Thu Jun 18 15:58:26 2015 Alaric
** Last update Mon Jun 22 17:08:12 2015 Alaric
*/

#include	<SDL2/SDL.h>
#include	<unistd.h>
#include	"include/graphic.h"
#include	"../include/server/map.h"

int		main()
{
  t_texture	text;
  SDL_Renderer	*renderer;
  SDL_Window	*fenetre;
  SDL_Rect	DestR;

  t_map		map;
  t_squarre	*item;

  item = malloc(sizeof(t_squarre));
  item->x = 5;
  item->y = 5;
  map.items = item;

  //position dans la fenetre
  DestR.x = map.items->x * (SIZE_X / 40) + 1;
  DestR.y = map.items->y * (SIZE_Y / 40) + 1;
  DestR.w = SHAPE_SIZE;
  DestR.h = SHAPE_SIZE;

  fenetre = init_video();
  renderer = init_renderer(fenetre);
  init_texture(&text, renderer);
  //clear de la fenetre
  SDL_RenderClear(renderer);
  //affichage BMP => a modif pour toutes les images
  draw_stone(&map, &text, renderer);
  //SDL_RenderCopy(renderer, text.phiras, NULL, &DestR);
  //Changement couleur pour la grille
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  draw_grid(renderer);
  //actualisation de l'affichage
  SDL_RenderPresent(renderer);

  sleep(5);

  SDL_Quit();
  return (0);
}
