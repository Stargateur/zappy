/*
** parser.c for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:34:46 2015 Antoine Plaskowski
** Last update Sun Jul  5 19:45:03 2015 Antoine Plaskowski
*/

#include	<string.h>
#include	<stddef.h>
#include	<stdlib.h>
#include	"parser.h"
#include	"action.h"
#include	"avance.h"
#include	"droite.h"
#include	"gauche.h"
#include	"voir.h"
#include	"inventaire.h"
#include	"prend.h"
#include	"pose.h"
#include	"expulse.h"
#include	"broadcast.h"
#include	"incantation.h"
#include	"egg.h"
#include	"connect_nbr.h"

static t_cmd	g_cmd[] =
  {
    {"avance", &avance, AVANCE, 7, sizeof("avance") - 1},
    {"droite", &droite, DROITE, 7, sizeof("droite") - 1},
    {"gauche", &gauche, GAUCHE, 7, sizeof("gauche") - 1},
    {"voir", &voir, VOIR, 7, sizeof("voir") - 1},
    {"inventaire", &inventaire, INVENTAIRE, 1, sizeof("inventaire") - 1},
    {"prend", &prend, PREND, 7, sizeof("prend") - 1},
    {"pose", &pose, POSE, 7, sizeof("pose") - 1},
    {"expulse", &expulse, EXPULSE, 7, sizeof("expulse") - 1},
    {"broadcast", &broadcast, BROADCAST, 7, sizeof("broadcast") - 1},
    {"incantation", &incantation, INCANTATION, 300, sizeof("incantation") - 1},
    {"fork", &egg, FORK, 42, sizeof("fork") - 1},
    {"connect_nbr", &connect_nbr, CONNECT_NBR, 0, sizeof("connect_nbr") - 1}
  };

static const size_t	g_size = sizeof(g_cmd) / sizeof(*g_cmd);

static t_action	*create_action(char *str, char *arg, t_cmd *cmd, size_t t)
{
  t_action	*action;

  if ((action = malloc(sizeof(*action))) == NULL)
    return (NULL);
  action->str = str;
  action->arg = arg;
  action->cmd = cmd;
  if (time_div(&action->time, cmd != NULL ? cmd->time : 0, t) == true)
    {
      free(action);
      return (NULL);
    }
  return (action);
}

t_action	*parser(char *str, size_t const t)
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
      return (create_action(str, str + j, g_cmd + i, t));
  free(str);
  return (create_action(NULL, NULL, NULL, 0));
}
