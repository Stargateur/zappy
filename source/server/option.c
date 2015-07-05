/*
** option.c for option in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:46:23 2015 Antoine Plaskowski
** Last update Sun Jul  5 18:34:31 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"option.h"

static t_option	*init_option(t_option * const option)
{
  static char	*team[] = {"team1", "team2", NULL};

  if (option == NULL)
    return (NULL);
  option->p = "4242";
  option->n = NULL;
  option->x = 42;
  option->y = 42;
  option->c = 1;
  option->g = false;
  option->t = 100;
  option->team = team;
  return (option);
}

bool		show_option(t_option * const option)
{
  size_t	i;

  if (option == NULL)
    return (true);
  printf("port : %s\n", option->p);
  printf("x : %lu\n", option->x);
  printf("y : %lu\n", option->y);
  printf("population : %lu\n", option->c);
  printf("t : %lu\n", option->t);
  if (option->team != NULL)
    {
      for (i = 0; option->team[i] != NULL; i++)
	printf("team = %lu : %s\n", i, option->team[i]);
      if (option->n != NULL)
	printf("team = %lu : %s\n", i, option->n);
    }
  return (false);
}

static bool	set_option(t_option * const option, char **argv,
			   int const c)
{
  if (c == 'p')
    option->p = optarg;
  else if (c == 'n')
    option->n = optarg;
  else if (c == 'g')
    option->g = true;
  else if (c == 'x')
    option->x = strtoul(optarg, NULL, 10);
  else if (c == 'y')
    option->y = strtoul(optarg, NULL, 10);
  else if (c == 'c')
    option->c = strtoul(optarg, NULL, 10);
  else if (c == 't')
    option->t = strtoul(optarg, NULL, 10);
  else if (c == 'h')
    {
      fprintf(stderr, "%s: [-p 4242] [-x 42] [-y 42] [-c 1] [-t 100]"
	      " [-n team1 team2 etc] [-g]\n", *argv);
      return (true);
    }
  else
    return (true);
  return (false);
}

bool		get_option(t_option * const option, char **argv, int const argc)
{
  int		c;
  bool		ret;

  if (option == NULL || argv == NULL)
    return (true);
  ret = false;
  init_option(option);
  while ((c = getopt(argc, argv, "ghp:x:y:c:t:n:")) != -1)
    if (set_option(option, argv, c) == true)
      ret = true;
  if (argv[optind] != NULL || option->n != NULL)
    option->team = argv + optind;
  return (ret);
}
