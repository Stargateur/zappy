/*
** parse_opt.c for parse_opt in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:46:23 2015 Antoine Plaskowski
** Last update Thu Jun 18 17:14:37 2015 Antoine Plaskowski
*/

#define		_XOPEN_SOURCE
#include	<stdbool.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	"parse_opt.h"

static bool	check_opt(t_opt const * const opt, bool	ret)
{
  return (ret);
}

bool		show_opt(t_opt const * const opt)
{
  printf("port : %s\n", opt->p);
  printf("x : %s\n", opt->x);
  printf("y : %s\n", opt->y);
  printf("population : %s\n", opt->c);
  printf("t : %s\n", opt->t);
  return (false);
}

bool		parse_opt(char * const * const argv, int const argc,
			  t_opt * const opt)
{
  int		c;
  bool		ret;

  if (opt == NULL)
    return (true);
  ret = false;
  memset(opt, 0, sizeof(*opt));
  while ((c = getopt(argc, argv, "p:x:y:c:t:")) != -1)
    {
      switch (c)
	{
	case 'p':
	  opt->p = optarg;
	  break;
	case 'x':
	  opt->x = optarg;
	  break;
	case 'y':
	  opt->y = optarg;
	  break;
	case 'c':
	  opt->c = optarg;
	  break;
	case 't':
	  opt->t = optarg;
	  break;
	default:
	  ret = true;
	  break;
    	}
    }
  for (c = optind; c < argc; c++)
    printf ("Non-option argument %s\n", argv[c]);
  return (check_opt(opt, ret));
}
