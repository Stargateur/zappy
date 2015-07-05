/*
** time_utils.c for time_utils in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 13:23:18 2015 Antoine Plaskowski
** Last update Sun Jul  5 04:58:29 2015 Antoine Plaskowski
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

bool		time_add(t_time * const a, t_time const * const b)
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
  if (a == NULL && b != NULL)
    return (true);
  if (b == NULL)
    return (false);
  if (a->tv_sec < b->tv_sec)
    return (true);
  else if (a->tv_sec == b->tv_sec)
    if (a->tv_nsec < b->tv_nsec)
      return (true);
  return (false);
}

bool		time_div(t_time * const a, size_t const num, size_t const dem)
{
  if (a == NULL)
    return (true);
  if (num == 0 || dem == 0)
    {
      a->tv_sec = 0;
      a->tv_nsec = 0;
      return (false);
    }
  a->tv_sec = num / dem;
  a->tv_nsec = num % dem * NANO_BY_SEC / dem;
  return (false);
}

bool		time_show(t_time const * const a)
{
  if (printf("time : %ld sec et %ld nanosec\n", a->tv_sec, a->tv_nsec) < 0)
    return (true);
  return (false);
}
