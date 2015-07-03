/*
** concat.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Jul  3 20:36:57 2015 zwertv_e
** Last update Fri Jul  3 21:10:40 2015 zwertv_e
*/

#include	<string.h>
#include	<stdlib.h>
#include	"player.h"

char		*concat(char *str1, char const * const str2,
			bool const do_free)
{
  size_t	to_malloc;
  char		*res;

  to_malloc = 1;
  if (str1 != NULL)
    to_malloc += strlen(str1);
  if (str2 != NULL)
    to_malloc += strlen(str2);
  res = malloc(sizeof(char) * to_malloc);
  res[0] = '\0';
  if (str1 != NULL)
    res = strcat(res, str1);
  if (str2 != NULL)
    res = strcat(res, str2);
  if (do_free == true && str1 != NULL)
    free(str1);
  return (res);
}
