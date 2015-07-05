/*
** utils.c for utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 15:38:21 2015 Antoine Plaskowski
** Last update Sun Jul  5 03:52:51 2015 Antoine Plaskowski
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdarg.h>
#include	<stdlib.h>
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

char		*malloc_vsnprintf(char *format, ...)
{
  va_list	ap;
  char		*str;
  int		len;

  va_start(ap, format);
  if ((len = vsnprintf(NULL, 0, format, ap)) < 0)
    return (NULL);
  va_end(ap);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (NULL);
  va_start(ap, format);
  if (vsnprintf(str, (size_t)len + 1, format, ap) != len)
    {
      free(str);
      return (NULL);
    }
  va_end(ap);
  return (str);
}
