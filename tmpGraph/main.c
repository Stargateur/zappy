/*
** main.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Thu Jun 18 15:58:26 2015 Alaric
** Last update Fri Jun 19 19:31:04 2015 Alaric
*/

//#include	<SDL/SDL_ttf.h>
#include	<SDL2/SDL.h>
//#include	<SDL/SDL_image.h>
#include	<unistd.h>
#define		SHAPE_SIZE 24

int		main()
{
  SDL_Window	*fenetre;
  SDL_Renderer	*renderer;
  SDL_Texture	*Linemate;
  //SDL_Surface	*grid;
  SDL_Surface	*linemate;
  SDL_Rect	SrcR;
  SDL_Rect	DestR;

  SrcR.x = 0;
  SrcR.y = 0;
  SrcR.w = SHAPE_SIZE;
  SrcR.h = SHAPE_SIZE;

  DestR.x = 24;
  DestR.y = 24;
  DestR.w = SHAPE_SIZE;
  DestR.h = SHAPE_SIZE;

  //fenetre = init_video();
  //SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &fenetre, &renderer);
  fenetre = SDL_CreateWindow("SDL_RenderCopy Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, 0);
  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  //SDL_RenderSetLogicalSize(renderer, 640, 580);
  linemate = Bmp_Loader("BMP/Linemate.bmp");
  Linemate = SDL_CreateTextureFromSurface(renderer, linemate);
  //grid = init_grid();
  //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, Linemate, &SrcR, &DestR);
  //SDL_RenderDrawLine(renderer, 25, 25, 25, 50);
  //SDL_RenderCopy(renderer, Linemate, NULL, NULL);
  SDL_RenderPresent(renderer);

  sleep(2);

  SDL_Quit();
  return (0);
}
