/*
** time_utils.c for time_utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 13:23:18 2015 Antoine Plaskowski
** Last update Sat Jul  4 13:51:40 2015 Antoine Plaskowski
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"time_utils.h"

bool		time_sub(t_time * const a, t_time const * const b)
{
  if (a == NULL || b == NULL)
    return (true);
  if (a->tv_sec < b->tv_sec)
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

bool		time_abb(t_time * const a, t_time const * const b)
{
  if (a == NULL || b == NULL)
    return (true);
  a->tv_sec += b->tv_sec;
  if (a->tv_nsec + b->tv_nsec >= NANO_BY_SEC)
    {
      a->tv_nsec -= NANO_BY_SEC;
      a->tv_sec += 1;
    }
  a->tv_nsec += b->tv_nsec;
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

bool		time_div(t_time * const a, size_t const num, size_t const dem)
{
  if (a == NULL || dem == 0)
    return (false);
  a->tv_sec = num / dem;
  a->tv_nsec = num % dem * NANO_BY_SEC / dem;
  return (true);
}
