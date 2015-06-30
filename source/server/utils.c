/*
** utils.c for utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 15:38:21 2015 Antoine Plaskowski
** Last update Tue Jun 30 17:00:29 2015 Antoine Plaskowski
*/

#include	<stddef.h>
#include	"opt.h"

size_t		len_tab(void * const * const tab)
{
  size_t	i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

size_t		find_team(char * const team)
{
  size_t	i;

  if (team == NULL)
    return (NULL);
  for (i = 0; opt.team[i] != NULL; i++)
    if (strcmp(opt.team[i], team) == 0)
      return (i);
  return (i);
}
