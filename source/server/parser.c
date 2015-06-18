/*
** parser.c for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:34:46 2015 Antoine Plaskowski
** Last update Thu Jun 18 23:55:04 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	<stddef.h>
#include	"parser.h"

static const struct s_fct_parse	g_fct[] =
  {
    {"avance", NULL},
    {"droite", NULL},
    {"gauche", NULL},
    {"voir", NULL},
    {"inventaire", NULL},
    {"prend", NULL},
    {"pose", NULL},
    {"expulse", NULL},
    {"broadcast", NULL},
    {"incantation", NULL},
    {"fork", NULL},
    {"connect_nbr", NULL}
  };

static const size_t	g_size = sizeof(g_fct) / sizeof(*g_fct);

void		parser(char *str)
{
  char const	*cmd;
  size_t	i;
  
  cmd = strtok(str, " \t\n");
  for (i = 0; i < g_size; i++)
    {
      if (strcmp(cmd, g_fct[i].cmd) == 0)
	return;
    }
}
