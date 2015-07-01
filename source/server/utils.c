/*
** utils.c for utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 15:38:21 2015 Antoine Plaskowski
** Last update Wed Jul  1 05:29:03 2015 Antoine Plaskowski
*/

#include	<stddef.h>
#include	"utils.h"

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
