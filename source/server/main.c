/*
** main.c for main in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Tue Jun 16 16:38:42 2015 Antoine Plaskowski
** Last update Thu Jun 18 17:56:10 2015 Antoine Plaskowski
*/

#include	<getopt.h>
#include	"parse_opt.h"

int		main(int argc, char **argv)
{
  t_opt		opt;

  parse_opt(argv, argc, &opt);
  show_opt(&opt);
  return (0);
}
