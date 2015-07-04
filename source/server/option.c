/*
** option.c for option in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:46:23 2015 Antoine Plaskowski
** Last update Sat Jul  4 17:53:58 2015 Antoine Plaskowski
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
  option->x = 42;
  option->y = 42;
  option->c = 1;
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
    for (i = 0; option->team[i] != NULL; i++)
      printf("%lu : %s\n", i, option->team[i]);
  return (false);
}

static char	*set_option(t_option * const option, char **argv,
			    int const c)
{
  switch (c)
    {
    case 'p':
      option->p = optarg;
      return (optarg);
    case 'x':
      option->x = strtoul(optarg, NULL, 10);
      return (optarg);
    case 'y':
      option->y = strtoul(optarg, NULL, 10);
      return (optarg);
    case 'c':
      option->c = strtoul(optarg, NULL, 10);
      return (optarg);
    case 't':
      option->t = strtoul(optarg, NULL, 10);
      return (optarg);
    case 'h':
      fprintf(stderr, "%s: [-p 4242] [-x 42] [-y 42] [-c 1] [-t 100]", *argv);
      fprintf(stderr, " Team1 Team2 etc\n");
      return (NULL);
    }
  return (NULL);
}

bool		get_option(t_option * const option, char **argv, int const argc)
{
  int		c;
  bool		ret;

  if (option == NULL || argv == NULL)
    return (true);
  ret = false;
  init_option(option);
  while ((c = getopt(argc, argv, "hp:x:y:c:t:")) != -1)
    if (set_option(option, argv, c) == NULL)
      ret = true;
  if (argv[optind] != NULL)
    option->team = argv + optind;
  return (ret);
}
