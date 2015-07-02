/*
** utils.c for utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 15:38:21 2015 Antoine Plaskowski
** Last update Thu Jul  2 18:40:55 2015 Antoine Plaskowski
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
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

bool		write_fd(char const * const str, int const fd)
{
  ssize_t	ret;

  if (str == NULL)
    return (true);
  ret = write(fd, str, strlen(str));
  if (ret == -1)
    {
      perror("write : ");
      return (true);
    }
  return (false);
}

bool		time_sub(t_time * const a, t_time const * const b)
{
  if (a == NULL || b == NULL)
    return (true);
  a->tv_sec -= b->tv_sec;
  if (a->tv_nsec < b->tv_nsec)
    {
      a->tv_nsec += NANO_BY_SEC;
      a->tv_sec -= 1;
    }
  a->tv_nsec -= b->tv_nsec;
  return (false);
}

bool		time_small(t_time const * const a, t_time const * const b)
{
  if (a == NULL)
    return (true);
  if (b == NULL)
    return (false);
  if (a->tv_sec < b->tv_sec)
    return (false);
  if (a->tv_nsec < b->tv_nsec)
    return (false);
  return (true);
}
