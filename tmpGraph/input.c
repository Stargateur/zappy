/*
** input.c for input in /home/costa_b/rendu/PSU_2014_zappy/tmpGraph
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Jun 22 15:34:38 2015 Kevin Costa
** Last update Mon Jun 22 16:49:00 2015 Kevin Costa
*/

//#include	

void update(Input *input)
{
  SDL_Event event;
  int a;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	a = 0; /* QUITTER */
      if (event.type == SDLK_ESCAPE)
	a = 0; /* QUITTER */
      if (event.type == SDLK_UP)
	a = 0; /* ZOOM +*/
      if (event.type == SDLK_DOWN)
	a = 0; /* ZOOM -*/
      if (event.type == SDLK_RIGHT)
	a = 0; /* decaler sur la gauche */
      if (event.type == SDLK_LEFT)
	a = 0; /* decaler sur la droite */
      if (event.type == SDLK_SPACE)
	a = 0; /* check la case actuel */
    }
}
