/*
** parser.c for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:34:46 2015 Antoine Plaskowski
** Last update Mon Jun 29 19:18:06 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	<stddef.h>
#include	"parser.h"

static t_cmd	g_cmd[] =
  {
    {"avance", NULL, 7},
    {"droite", NULL, 7},
    {"gauche", NULL, 7},
    {"voir", NULL, 7},
    {"inventaire", NULL, 1},
    {"prend", NULL, 7},
    {"pose", NULL, 7},
    {"expulse", NULL, 7},
    {"broadcast", NULL, 7},
    {"incantation", NULL, 300},
    {"fork", NULL, 42},
    {"connect_nbr", NULL, 0}
  };

static const size_t	g_size = sizeof(g_cmd) / sizeof(*g_cmd);

t_cmd		*parser(char *str)
{
  size_t	i;
  size_t	j;

  if (str == NULL)
    return (NULL);
  while (*str == ' ')
    str++;
  j = 0;
  while (str[j] != ' ' || str[j] != '\0')
    j++;
  for (i = 0; i < g_size; i++)
    if (strncmp(str, g_cmd[i].cmd, j) == 0)
      return (g_cmd + i);
  return (NULL);
}
