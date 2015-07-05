/*
** size_map.c for size_map in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Jul  5 14:45:30 2015 Antoine Plaskowski
** Last update Sun Jul  5 14:51:34 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	"client.h"
#include	"map.h"
#include	"size_map.h"

bool		write_size_map(t_client *client, size_t x, size_t y)
{
  char		*str;

  str = malloc_vsnprintf("%lu %lu\n", x, y);
  if (str == NULL)
    return (true);
  if (add_string(client, str) == true)
    return (true);
  free(str);
  return (false);
}
