/*
** opt.c for opt in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:46:23 2015 Antoine Plaskowski
** Last update Wed Jul  1 04:40:39 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"opt.h"

static t_opt	*init_opt(t_opt * const opt)
{
  static char	*team[] = {"team1", "team2", NULL};

  if (opt == NULL)
    return (true);
  opt->p = "4242";
  opt->x = 42;
  opt->y = 42;
  opt->c = 1;
  opt->t = 100;
  opt->team = team;
}

bool		show_opt(t_opt * const opt)
{
  size_t	i;

  if (opt == NULL)
    return (true);
  printf("port : %s\n", opt->p);
  printf("x : %lu\n", opt->x);
  printf("y : %lu\n", opt->y);
  printf("population : %lu\n", opt->c);
  printf("t : %lu\n", opt->t);
  if (opt->team != NULL)
    for (i = 0; opt->team[i] != NULL; i++)
      printf("%s\n", opt->team[i]);
  return (false);
}

static char	*ana_opt(t_opt * const opt, char **argv,
			 int const c)
{
  switch (c)
    {
    case 'p':
      opt->p = optarg;
      return (optarg);
    case 'x':
      opt->x = strtoul(optarg, NULL, 10);
      return (optarg);
    case 'y':
      opt->y = strtoul(optarg, NULL, 10);
      return (optarg);
    case 'c':
      opt->c = strtoul(optarg, NULL, 10);
      return (optarg);
    case 't':
      opt->t = strtoul(optarg, NULL, 10);
      return (optarg);
    case 'h':
      fprintf(stderr, "%s: [-p 4242] [-x 42] [-y 42] [-c 1] [-t 100]", *argv);
      fprintf(stderr, " Team1 Team2\n");
      return (NULL);
    }
  return (NULL);
}

bool		get_opt(t_opt * const opt, char **argv, int const argc)
{
  int		c;
  bool		ret;

  if (opt == NULL || argv == NULL)
    return (true);
  ret = false;
  init_opt(opt);
  while ((c = getopt(argc, argv, "hp:x:y:c:t:")) != -1)
    if (ana_opt(opt, argv, c) == NULL)
      ret = true;
  if (argv[optind] != NULL)
    opt->team = argv + optind;
  return (ret);
}
