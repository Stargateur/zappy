/*
** parser.c for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:34:46 2015 Antoine Plaskowski
** Last update Tue Jun 30 20:11:46 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	<stddef.h>
#include	<stdlib.h>
#include	"parser.h"
#include	"action.h"

static t_cmd	g_cmd[] =
  {
    {"avance", AVANCE, 7, sizeof("avance")},
    {"droite", DROITE, 7, sizeof("droite")},
    {"gauche", GAUCHE, 7, sizeof("gauche")},
    {"voir", VOIR, 7, sizeof("voir")},
    {"inventaire", INVENTAIRE, 1, sizeof("inventaire")},
    {"prend", PREND, 7, sizeof("prend")},
    {"pose", POSE, 7, sizeof("pose")},
    {"expulse", EXPULSE, 7, sizeof("expulse")},
    {"broadcast", BROADCAST, 7, sizeof("broadcast")},
    {"incantation", INCANTATION, 300, sizeof("incantation")},
    {"fork", FORK, 42, sizeof("fork")},
    {"connect_nbr", CONNECT_NBR, 0, sizeof("connect_nbr")}
  };

static const size_t	g_size = sizeof(g_cmd) / sizeof(*g_cmd);

static t_action	*create_action(char *str, char *arg, t_cmd *cmd)
{
  t_action	*action;

  if ((action = malloc(sizeof(*action))) == NULL)
    return (NULL);
  action->str = str;
  action->arg = arg;
  action->cmd = cmd;
  return (action);
}

t_action	*parser(char *str)
{
  size_t	i;
  size_t	j;

  if (str == NULL)
    return (NULL);
  while (*str == ' ')
    str++;
  if ((str = strdup(str)) == NULL)
    return (NULL);
  j = 0;
  while (str[j] != ' ' && str[j] != '\0')
    j++;
  for (i = 0; i < g_size; i++)
    if (strncmp(str, g_cmd[i].cmd, g_cmd[i].len_cmd) == 0)
      return (create_action(str, str + j, g_cmd + i));
  return (NULL);
}
