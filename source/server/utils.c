/*
** utils.c for utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 15:38:21 2015 Antoine Plaskowski
** Last update Sat Jul  4 22:15:11 2015 Antoine Plaskowski
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
  va_list	cpy;
  char		*str;
  int		len;

  va_start(ap, format);
  va_copy(cpy, ap);
  if ((len = vsnprintf(NULL, 0, format, ap)) < 0)
    return (NULL);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (NULL);
  if (snprintf(str, (size_t)len + 1, format, cpy) != len)
    {
      free(str);
      return (NULL);
    }
  va_end(ap);
  return (str);
  
}
