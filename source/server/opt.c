/*
** opt.c for opt in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:46:23 2015 Antoine Plaskowski
** Last update Thu Jun 18 22:51:32 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	"opt.h"

static t_opt	*init_opt(t_opt * const opt)
{
  opt->p = "4242";
  opt->x = "42";
  opt->y = "42";
  opt->c = "1";
  opt->t = "100";
  opt->team = NULL;
  return (opt);
}

bool		show_opt(t_opt const * const opt)
{
  int		i;

  if (opt == NULL)
    return (false);
  printf("port : %s\n", opt->p);
  printf("x : %s\n", opt->x);
  printf("y : %s\n", opt->y);
  printf("population : %s\n", opt->c);
  printf("t : %s\n", opt->t);
  if (opt->team != NULL)
    {
      i = 0;
      while (opt->team[i] != NULL)
	printf("%s\n", opt->team[i++]);
    }
  return (false);
}

static char	*ana_opt(t_opt * const opt, int const c)
{
  switch (c)
    {
    case 'p':
      opt->p = optarg;
      return (optarg);
    case 'x':
      opt->x = optarg;
      return (optarg);
    case 'y':
      opt->y = optarg;
      return (optarg);
    case 'c':
      opt->c = optarg;
      return (optarg);
    case 't':
      opt->t = optarg;
      return (optarg);
    }
  return (NULL);
}

bool		get_opt(char * const * const argv, int const argc, t_opt * const opt)
{
  int		c;
  bool		ret;

  if (opt == NULL)
    return (true);
  ret = false;
  init_opt(opt);
  while ((c = getopt(argc, argv, "p:x:y:c:t:")) != -1)
    if (ana_opt(opt, c) == NULL)
      ret = true;
  opt->team = argv + optind;
  return (ret);
}
